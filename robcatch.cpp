#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
 using namespace cv;

 int threshold_value=118;
 int threshold_type=0;
 int max_BINARY_value=threshold_value;

const char* window_name = "thief";
Mat image,image_gray,dst;

int main(int argc,char** argv)
{
	bool copyData=false;

CvCapture* webcam=cvCreateCameraCapture(0);
if(!webcam)
{
	return -1;

}
while(1)
{
const IplImage* image1=cvQueryFrame(webcam);
Mat image = cv::cvarrToMat(image1); 

if(image)
{
//Process it;
//Threshold binary
cvtColor(image,image_gray,CV_BGR2GRAY);

//Initialized
threshold(image_gray,dst,threshold_value,max_BINARY_value,threshold_type);
//Output Video
imshow(window_name,dst);

cvNamedWindow(window_name,1);

cvShowImage(window_name,image);


//if(/*there is a thief in the image use the following code*/){
//cvSaveImage("/home/rahul/Dropbox/rahul.jpg",image,0);

}

  }
    }



