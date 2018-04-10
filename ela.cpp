#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

Mat ela_implementation(Mat image, int compression_factor) {

 // Takes in the image, compresses the image and returns the result
    std::vector <int> params;
    params.push_back(CV_IMWRITE_JPEG_QUALITY);
    params.push_back(compression_factor);
    Mat comp_image; 
    comp_image = cv::imwrite("compressed.jpg",image,params);

// Split the image into different channels RGB
    Mat uncomp_bgr[3];
    Mat comp_bgr[3];
    split(image,uncomp_bgr);
    split(comp_image, comp_bgr);

// Stores the difference between the components of channels of comp
// ressed and uncompressed image  
    Mat diff[3];
// blue channel difference 
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

    merge(channels,final);

// Storing the diff image
    imwrite("diff.jpg", final);
//   Mat diff_img;
    diff_img = imread("diff.jpg" ,1);
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", diff_img );  
    return diff_img;
}
 
int main(int argc, char** argv) {
    //int multiplier=30;
    int compression_value=95;
    Mat img;
    /*running ela on original image taken by mobile*/
    img = imread(argv[1],0);
    Mat ela_result_img = ela_implementation(img,compression_value);
    imwrite("result_original_img.jpg",ela_result_img);

    /*running ela on photoshopped image which have a logo added in original image saved at 100% quality jpeg*/
    //Mat edited_img;
    //edited_img=imread("photoshopped_img.jpg");
    //Mat ela_result_edited_img=ela_algorithm(edited_img,compression_value, multiplier);
    //imwrite("result_edited_img.jpg",ela_result_edited_img);
    return 0;
}