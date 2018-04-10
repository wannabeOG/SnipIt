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
    Mat comp_image = cv::imwrite("compressed.jpeg",image,params);



}
 
