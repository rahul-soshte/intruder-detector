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

int main(int argc, char** argv)
{
	int m=0;
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
            calcOpticalFlowFarneback(prevgray, gray, flow, 0.5, 3, 15, 3, 5, 1.2, 0);
           imshow("flow", gray);
          

    float threshold = 10.0f;
    float dist;

    for(int j=0; j<flow.rows; ++j)
        for(int i=0; i<flow.cols; ++i)
        {
           
        	  Point2f& fxy = flow.at<Point2f>(j, i);

Point2f a(i,j);
Point2f b(i+fxy.x,j+fxy.y);
double dist = cv::norm(cv::Mat(a),cv::Mat(b));

            if(dist>threshold)
            {
               // foregroundMask.at<unsigned char>(j,i) = 255;
            	   imwrite("/home/hunter/Desktop/rahul.jpg",frame);
            	   exit(1);

 
            }
        }

        }
        if(waitKey(30)>=0)
            break;
        std::swap(prevgray, gray);
    }
    return 0;
}
