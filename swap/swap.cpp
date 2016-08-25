#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc,char** argv)
{
	Mat image1,image2;
namedWindow("image1",WINDOW_NORMAL);
namedWindow("image2",WINDOW_NORMAL);

image1=imread("ns.jpg");
image2=imread("fer.jpg");

	swap(image1,image2);
	
	imshow("image1",image1);
	imshow("image2",image2);
waitKey(0);

	return 0;

}