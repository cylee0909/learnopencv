#include<opencv2/opencv.hpp>
using namespace cv;

int testVideo() {
	VideoCapture capture(0);
	while(1) {
		Mat frame;
		capture >> frame;
		imshow("摄像头采集", frame);
		waitKey(30);
	}
	return 0;
}
