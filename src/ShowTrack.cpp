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
Mat dstImg;
void onTrackChange(int val, void *) {
	cout << "当前值是" << val << endl;
	rotate(rawImg, dstImg, val / 10 % 2);
	imshow(WINDOW_NAME, dstImg);
}

int showTrack() {
	// 【1】读入一张图片，载入图像
	rawImg = imread("img1.jpg");
	namedWindow(WINDOW_NAME, 1);
	String trackName("滑块");
	createTrackbar(trackName, WINDOW_NAME, &trackVal, maxVal, onTrackChange);
	onTrackChange(trackVal, 0);
	waitKey(0);
	return 0;
}


