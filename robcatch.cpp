#include<stdio.h>
#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc,char** argv)
{
CvCapture* webcam=cvCreateCameraCapture(0);
if(!webcam)
{
	//Exit with an error
	
}
while(1)
{
Mat image=cvQueryFrame(webcam);

if(image)
{
//Process it;
//Threshold binary inverted

//if there is a thief in the image use the following code
//cvSaveImage("somefile.jpg",image,0);

}
}

cvNamedWindow("thief",1);
cvShowImage("Thief");

}