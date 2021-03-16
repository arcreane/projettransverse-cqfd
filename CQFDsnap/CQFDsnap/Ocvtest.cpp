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

		vector<Rect> faces;
		faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(30, 30));

		for (Rect area : faces)
		{
	
			Scalar drawColor = Scalar(255, 255, 64);

			rectangle(frame, Point(cvRound(area.x * scale), cvRound(area.y * scale)), Point(cvRound((area.x + area.width - 1) * scale),
				cvRound((area.y + area.height - 1) * scale)), drawColor);
				
			
			
				

		}
		
		imshow("webcam frame", frame);
		

		if (waitKey(30) >= 0)
			break;
	}
	



}