#include <string>
#include <iostream>
#include <memory>
#include "binary_mask.h"
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {

	// Validate parameter
	if (argc != 2)
	{
		std::cout << "USE: " << argv[0] << " <file_path>" << std::endl;
		return -1;
	}

	std::string inputFile = argv[1];
	if (inputFile.size() <= 0)
	{
		std::cout << "Invalid file path!" << std::endl;
		return -1;
	}

	cv::Mat maskImage;

	std::shared_ptr<imageoperations::BinaryMask> binaryMask = std::make_shared<imageoperations::BinaryMask>();
	binaryMask->Create(argv[1], maskImage);

	return 0;
}
