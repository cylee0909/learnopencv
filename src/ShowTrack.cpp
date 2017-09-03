/*
 * ShowTrack.cpp
 *
 *  Created on: 2017年8月28日
 *      Author: cylee
 */

#include <opencv2/opencv.hpp>  //头文件
#include <iostream>
using namespace cv;
using namespace std;

#define WINDOW_NAME "滑块窗口"
const int maxVal = 100;
int trackVal;
Mat rawImg;
Mat dstImg(100, 100, CV_8UC3);
void onTrackChange(int val, void *) {
	cout << "当前值是" << val << endl;
//	rotate(rawImg, dstImg, val / 10 % 2);
//	if (dstImg == NULL) {
//		dstImg = rawImg;
//	}
	imshow(WINDOW_NAME, rawImg);
}

void onMouseChange(int event, int x, int y, int flags, void* userdata) {
	cout << "Mouse event = " << event << " x = "<< x << " y = "<< y << endl;
}

int showTrack() {
	// 【1】读入一张图片，载入图像
	rawImg = imread("img1.jpg");
	namedWindow(WINDOW_NAME, 1);
	String trackName("滑块");
	createTrackbar(trackName, WINDOW_NAME, &trackVal, maxVal, onTrackChange);
	onTrackChange(trackVal, 0);

	// 设置鼠标监听
	setMouseCallback(WINDOW_NAME, onMouseChange);

	return 0;
}


