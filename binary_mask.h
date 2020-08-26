#pragma once
#include <opencv2/opencv.hpp>

namespace imageoperations {

	class BinaryMask
	{
	public:

		BinaryMask();
		~BinaryMask();

		/*
		* Create binary mask of given input image.
		*
		* @param _filePath input image path
		* @param _output generated binary mask
		* @param _displayResult display result images if true
		* @return status true if mask created successfully, false if any error occured
		*/
		bool Create(const std::string& _filePath, cv::Mat& _output, const bool _displayResult = true);

	private:

		/*
		* Apply image subtraction to the given roi. Used in async operation.
		*
		* @param _filePath input image path
		* @param _image loaded image (BGR format)
		* @return status true if image loaded successfully, false if any error occured
		*/
		bool LoadImage(const std::string& _filePath, cv::Mat& _image);

	private:

	};
}