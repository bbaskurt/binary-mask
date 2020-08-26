#include "binary_mask.h"

imageoperations::BinaryMask::BinaryMask()
{
}

imageoperations::BinaryMask::~BinaryMask()
{
}

bool imageoperations::BinaryMask::Create(const std::string & _filePath, cv::Mat & _output, const bool _displayResult)
{
	cv::Mat inputImage; 
	if (!LoadImage(_filePath, inputImage))
		return false;

	//Grayscale image
	cv::Mat grayscaleImage(inputImage.size(), CV_8U);

	//Convert BGR to Gray
	cv::cvtColor(inputImage, grayscaleImage, CV_BGR2GRAY);

	//Binary image
	cv::Mat binaryImage(grayscaleImage.size(), grayscaleImage.type());

	//Denoised image 
	cv::Mat denoisedImage(inputImage.size(), CV_8U);

	// Apply gaussian blur to remove the noise 
	cv::GaussianBlur(grayscaleImage, denoisedImage, cv::Size(5, 5), 2, 0);

	if (_displayResult)
	{
		//Show the denoised image
		cv::namedWindow("Denoised", cv::WINDOW_AUTOSIZE);
		cv::imshow("Denoised", denoisedImage);
		cv::waitKey(10);
	}

	// Apply adaptive (local) threshold to obtain better result especially on low-resolution, noisy images.
	cv::adaptiveThreshold(denoisedImage, binaryImage, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 5, -2);

	if (_displayResult)
	{
		//Show the results
		cv::namedWindow("Binary", cv::WINDOW_AUTOSIZE);
		cv::imshow("Binary", binaryImage);
		cv::waitKey(10);
	}

	//Morphological operated image
	cv::Mat morphImage(grayscaleImage.size(), grayscaleImage.type());

	// Apply dilation and erosion recursively to fill the mask while preserving shape of the object. 
	cv::Mat kernelMorp = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(binaryImage, morphImage, kernelMorp, cv::Point(-1, -1), 9);
	cv::erode(morphImage, morphImage, kernelMorp, cv::Point(-1, -1), 7);

	// save binary mask
	cv::imwrite("binaryMask.jpg", morphImage);

	if (_displayResult)
	{
		//Show the results
		cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);
		cv::imshow("Result", morphImage);
		cv::waitKey(0);
	}

	return true;
}

bool imageoperations::BinaryMask::LoadImage(const std::string & _filePath, cv::Mat & _image)
{
	try
	{
		//Read input image
		_image = cv::imread(_filePath, CV_LOAD_IMAGE_COLOR);
		if (_image.empty())
		{
			std::cerr << "ERROR: Could not read image " << _filePath << std::endl;
			return false;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}
