# binary-mask
A simple C++ application to take an images and generate a binary mask. Binary mask is both displayed and saved as "binaryMask.jpg" file into the current directory. 

How to compile:

Windows: 
- Use simple CMake file to create Visual Studio project (Tested on CMake 3.2 and Visual Studio 2015).
Application uses OpenCV for image processing operations. Uploaded OpenCV dependencies are built on Visual Studio 2015 for 64-bit system. 
If you use your own OpenCV libraries, you can use any version of Visual Studio.

- "opencv" folder inside the main project folder must be added to either system path or Visual Studio runtime path to load OpenCV dll file. 
(Note: Only release version of the libraries have been loaded because of the large size of debug libraries.)

Linux: Not supported!

How to run:
> "binary_mask.exe <file_path>"