#include<stdio.h>
#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc,char** argv)
{
CvCapture* webcam=cvCreateCameraCapture(0);
if(!webcam)
while(1)
{
Mat image=cvQueryFrame(webcam);
}
if(!image)
{
//Process it;
}
cvSaveImage("somefile.jpg",image,0);
cvNamedWindow("thief",1);
cvShowImage("Thief");

}