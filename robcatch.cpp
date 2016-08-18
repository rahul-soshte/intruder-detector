//#include <iostream>
//#include "opencv2/imgproc.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
 
 using namespace cv;

 int threshold_value=118;
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

Mat image_gray,dst;
namedWindow("image_gray",1);
namedWindow("dst",1);

for(;;)
{

Mat frame;
cap>>frame;
cvtColor(frame, image_gray, CV_BGR2GRAY);
//Process it;
//Threshold binary
//Initialized
threshold(image_gray,dst,threshold_value,max_BINARY_value,0);
//Output Video
imshow("image_gray",image_gray);

imshow("dst",dst);

//if(/*there is a thief in the image use the following code*/){
//cvSaveImage("/home/rahul/Dropbox/rahul.jpg",image,0);
if(waitKey(30)>=0) break;

}

  return 0;


    }



