// File: ela.cpp
// Author: Saihimal Allu
// Usage: The following module is a basic implementation of Error Level 
// Analysis (ELA) algorithm to detect any external changes made to a 
// image through image editing software like Photoshop 

// Importing the libraries

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

Mat ela_implementation(Mat image, int compression_factor, int multiplier) {

 // Takes in the image, compresses the image and returns the result
 // cout << image.channels() << endl;
 //   Mat image;
 //   image = image = imread("image.jpg",CV_LOAD_IMAGE_COLOR);
    std::vector <int> params;
    params.push_back(CV_IMWRITE_JPEG_QUALITY);
    params.push_back(compression_factor);
    Mat comp_image;
    Mat comp_image2; 
 // cv::cvtColor(image, image, CV_BGR2RGB);
    comp_image = cv::imwrite("compressed.jpg",image,params);
 // Done so as to ensure that the imwrite function which reduces the
 // number of channels can be boosted up to the original number   
    comp_image2 = cv::imread("compressed.jpg", CV_LOAD_IMAGE_COLOR);
 //  cout << comp_image2.channels() << endl;

 // Split the image into different channels RGB
    Mat uncomp_bgr[3];
    Mat comp_bgr[3];
    split(image,uncomp_bgr);
    split(comp_image2, comp_bgr);
    
 // Stores the difference between the components of channels of comp
 // ressed and uncompressed image  
    Mat diff[3];
 // Blue channel difference 
    absdiff(comp_bgr[0],uncomp_bgr[0],diff[0]);
 // Green channel difference 
    absdiff(comp_bgr[1],uncomp_bgr[1],diff[1]);
 // Red channel difference
    absdiff(comp_bgr[2],uncomp_bgr[2],diff[2]);

 // Combine the channels of the diff object to get the difference image

 // Final image declaration 
    Mat final;
    Mat diff_img;
    std::vector <Mat> channels;
    channels.push_back(diff[0]);
    channels.push_back(diff[1]);
    channels.push_back(diff[2]);

 // Merge the single-array channels into a BGR image  
    merge(channels,final);

 // Storing the diff image
    imwrite("diff.jpg", final);
    
    Mat diff_image = imread("diff.jpg",CV_LOAD_IMAGE_COLOR);

    for (int i = 0; i< image.rows; ++i) {

        uchar* p = diff_image.ptr <uchar> (i);

        for (int j = 0; j<image.cols; ++j) {

            for (int Channel = 0; Channel <3; ++Channel) {

                // Thresholdig operation 
                if(p[Channel]*multiplier>255) p[Channel] = 255;
                // Scaling the differeces
                else p[Channel] = p[Channel]*multiplier;
            }

            p+=3;
        } 
    }
 // 
 // diff_img = imread("diff.jpg" ,1);
 // namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
 // imshow( "Display window", diff_img );  
    return diff_image;
       
}
 
int main(int argc, char** argv) {
    
    int compression_value=75;
    int multiplier=30;
    Mat image;
    /*running ela on original image taken by mobile*/
    image = imread(argv[1],CV_LOAD_IMAGE_COLOR);
    //cv::Size s = img.size();
    //int rows = s.height;
    //nt cols = s.width;
    //cout << rows << " " << cols <<endl;
    //cout << "Hello World" << endl;
    
    Mat elaResult_img;
    
    if (argc!=2 || image.empty()) {
        cout << "could not load image !" << endl;
    } 

     else{
        elaResult_img = ela_implementation(image,compression_value,multiplier);
    }    
    
    imwrite("ela_implemented_img.jpg",elaResult_img);
  
}
