#include <opencv2/opencv.hpp>
#include <iostream>
#include <iostream>
#include <vector>


using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{

	double scale = 3.5;
	string key;

	CascadeClassifier faceCascade;
	faceCascade.load("D:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml");

	VideoCapture cap(0);

	if (!cap.isOpened())
		return -1;

	for (;;)
	{

		Mat frame;
		Mat imgcanney;
		cap >> frame;

		Mat grayscale;
		cvtColor(frame, grayscale, COLOR_BGR2GRAY);
		resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));





		imshow("webcam frame", frame);


		if (waitKey(30) >= 0)
			break;
	}




}