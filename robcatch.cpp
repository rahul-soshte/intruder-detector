#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
 
 using namespace cv;

 int threshold_value=80;
 int threshold_type=0;
 int max_BINARY_value=255;


int main(int argc,char** argv)
{
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		/* code */
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

 */
 //Optical Flow

 //Build its Pyramid 
 //Use the DownScaled Version for detection
 //For iteration create lookup table
 //            
//Farneback Function             
calcOpticalFlowFarneback(prev_dst,dst,0.5,         
//swap function 
    
//And then above a number it will giv output as thief caught
//if(/*there is a thief in the image use the following code*/){
//cvSaveImage("/home/rahul/Dropbox/rahul.jpg",image,0);
if(waitKey(30)>=0) break;

}

  return 0;


    }



