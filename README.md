# Error Level Analysis using C++ and OpenCV #

## About the Project ##

### The Algorithm ###
Error Level Analysis (ELA) permits identifying areas within an image that are at different compression levels. With JPEG images, 
the entire picture should be at roughly the same level. If a section of the image is at a significantly different error level, 
then it likely indicates a digital modification. ELA highlights differences in the JPEG compression rate. Regions with uniform 
coloring, like a solid blue sky or a white wall, will likely have a lower ELA result (darker color) than high-contrast edges.

### Implementation Details ###
To run the code you need to have the following requirements installed in your system

* opencv 2.4
* cython 0.28.1
* python 2.7 (fails with python3, haven't figured out the reason yet)
* g++ any version

### Description of the folders and files in the repository ###
1. **Initial_Test**: Contains the images on which I tested the implementation of the algorithm in C++ sans the python wrapper
2. **Photoshop_Test**: Contains the images on which I tested the implementation of the wrapper and in a sense the working of thw whole 
project.
3. **Wrapper_Files**:
  * ela.hpp: Contains the function definitions that were used in the file ela_cython.cpp.
  * setup.py: Builds the wrapper.cpp file which makes the function callable from a python scripts.
  * wrapper.pyx: Cython file which acts as the interface between the C++ code and the python interpreter.
4. **ela.cpp**: The first implementation of the algorithm in C++. Works fine on it's own 
5. **ela_cython.cpp**: The actual code for the algorithm modified to make it compatible with the cython compiler.
6. **run.py** : The file to run on your python interpreter.

### Using it on your own system ###
1. Clone this repository onto your own local system.
2. Collapse the **Wrapper_Files** folder and bring them into the main project. 
3. Open a python interpreter and pass the name of the image you want to test out the algorithm as an argument to the **run.py** file.

You should get the following images
* **compressed.jpeg**: This is the image which was compressed from the original image.
* **diff.jpeg**: This image illustates the difference in the compressed and the original image.
* **ela_implemented_jpeg**: Scales up the diff.jpeg image to better illustrate the differences in the two images.

## Results ##

### Original Photos ###

Test Image             |  Photoshopped image
:-------------------------:|:-------------------------:
![](https://github.com/wannabeOG/image/blob/master/Photoshop_Test/test.jpeg)  |  ![](https://github.com/wannabeOG/image/blob/master/Photoshop_Test/photoshopped_test.jpeg)
<br>
<br>
<br>

### After Applying ELA on Photoshopped image ###
<p align="center">
  <img src="https://github.com/wannabeOG/image/blob/master/Photoshop_Test/ela_implemented_img.jpg" alt="Size Limit example"
       width="600" height="600">
</p>

The strong presence of rainbowing near the ballon regions only suggests that an Adobe product, like Photoshop or Lightroom, was used to save the image. It does not identify intentional modifications. 
