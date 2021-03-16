#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


// Importing Images


void main(int argc, char** argv) {
    VideoCapture cap(0);
    Mat frame;

    if (!cap.isOpened())
        throw "Error when reading the stream";

    namedWindow("w", 1);
    for (; ; )
    {
        while (frame.empty()) {
            cap >> frame;
        }
        //if(!frame)
        //    break;
        imshow("w", frame);
        waitKey(20); // waits to display frame
    }
    waitKey(0);
}