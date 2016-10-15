#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
 
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

 int threshold_value=80;
 int threshold_type=0;
 int max_BINARY_value=255;

 static void help()
{
    cout <<
            "\nThis program demonstrates dense optical flow algorithm by Gunnar Farneback\n"
            "Mainly the function: calcOpticalFlowFarneback()\n"
            "Call:\n"
            "./fback\n"
            "This reads from video camera 0\n" << endl;
}
/************************
not copy main

int main(int argc,char** argv)
{
	VideoCapture cap(0);
	if (!cap.isOpened())
	{

		return -1;

	}

Mat image_gray,dst,prev_dst,flow;
namedWindow("image_gray",1);
namedWindow("dst",1);
namedWindow("frame",1);


for(;;)
{

Mat frame;
cap>>frame;
cvtColor(frame, image_gray, CV_RGB2GRAY);
//Process it;
//Threshold binary
//Initialized
threshold(image_gray,dst,threshold_value,max_BINARY_value,threshold_type);
//Output Video
imshow("image_gray",image_gray);//GrayScale
imshow("dst",dst);//Binary Threshold
imshow("frame",frame);//Webcam output
//Use the dst pixels and calculate their position change in them
 /*

C++: void calcOpticalFlowFarneback(InputArray prev, InputArray next, InputOutputArray flow, double pyr_scale, int levels, int winsize, 
int iterations, int poly_n, double poly_sigma, int flags)

Parameters:	

        prev – first 8-bit single-channel input image.
        next – second input image of the same size and the same type as prev.
        flow – computed flow image that has the same size as prev and type CV_32FC2.
        pyr_scale – parameter, specifying the image scale (<1) to build
         pyramids for each image; pyr_scale=0.5 means a classical pyramid, where each next layer is twice smaller than the previous one.
        levels – number of pyramid layers including the initial image; 
        levels=1 means that no extra layers are created and only the original images are used.
        winsize – averaging window size; larger values increase the algorithm 
        robustness to image noise and give more chances for fast motion detection, but yield more blurred motion field.
        iterations – number of iterations the algorithm does at each pyramid level.
        poly_n – size of the pixel neighborhood used to find polynomial expansion in each pixel;
         larger values mean that the image will be approximated with smoother surfaces,
          yielding more robust algorithm and more blurred motion field, typically poly_n =5 or 7.
        poly_sigma – standard deviation of the Gaussian that is used to smooth derivatives used as a basis for the polynomial expansion;
         for poly_n=5, you can set poly_sigma=1.1, for poly_n=7, a good value would be poly_sigma=1.5.
        flags –

        operation flags that can be a combination of the following:
            OPTFLOW_USE_INITIAL_FLOW uses the input flow as an initial flow approximation.
            OPTFLOW_FARNEBACK_GAUSSIAN uses the Gaussian \texttt{winsize}\times\texttt{winsize} filter instead of a box 
            filter of the same size for
             optical flow estimation; usually, this option gives z more accurate flow than with a box filter, at the cost of lower speed; normally,
             winsize for a Gaussian window should be set to a larger value to achieve the same level of robustness.


 //Optical Flow

 //Build its Pyramid 
 //Use the DownScaled Version for detection
 //For iteration create lookup table
 //            
//Farneback Function             
calcOpticalFlowFarneback(prev_dst,dst,0.5,         
//swap function 
    
//And then above a number it will giv output as thief caught
//if(/*there is a thief in the image use the following code){
//cvSaveImage("/home/rahul/Dropbox/rahul.jpg",image,0);
if(waitKey(30)>=0) break;

}


  return 0;


    }
*/
static void drawOptFlowMap(const Mat& flow, Mat& cflowmap, int step,
                    double, const Scalar& color)
{
    for(int y = 0; y < cflowmap.rows; y += step)
        for(int x = 0; x < cflowmap.cols; x += step)
        {
            const Point2f& fxy = flow.at<Point2f>(y, x);
            line(cflowmap, Point(x,y), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),
                 color);
            circle(cflowmap, Point(x,y), 2, color, -1);
        }
}

int main(int argc, char** argv)
{
    cv::CommandLineParser parser(argc, argv, "{help h||}");
    if (parser.has("help"))
    {
        help();
        return 0;
    }
    VideoCapture cap(0);
    help();
    if( !cap.isOpened() )
        return -1;

    Mat flow, cflow, frame;
    UMat gray, prevgray, uflow;
    namedWindow("flow", 1);

    for(;;)
    {
        cap >> frame;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        if( !prevgray.empty() )
        {
            calcOpticalFlowFarneback(prevgray, gray, uflow, 0.5, 3, 15, 3, 5, 1.2, 0);
            cvtColor(prevgray, cflow, COLOR_GRAY2BGR);
            uflow.copyTo(flow);
            drawOptFlowMap(flow, cflow, 16, 1.5, Scalar(0, 255, 0));
            imshow("flow", cflow);
        }
        if(waitKey(30)>=0)
            break;
        std::swap(prevgray, gray);
    }
    return 0;
}

