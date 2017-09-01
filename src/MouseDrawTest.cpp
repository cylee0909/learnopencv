/*
 * MouseDrawTest.cpp
 *
 *  Created on: 2017年8月30日
 *      Author: cylee
 */

#include "MouseDrawTest.h"
#include <opencv2/opencv.hpp>  //头文件
#include <iostream>
using namespace cv;
using namespace std;

#define WINDOW_NAME "绘制窗口"
Rect g_rect;
RNG rng(12345);

MouseDrawTest::MouseDrawTest() {
}

int downX;
int downY;
bool drawing = false;
void drawRect(Mat& img, Rect& rect);
void mouseChange(int event, int x, int y, int flags, void* userdata) {
	cout << "Mouse event = " << event << " x = " << x << " y = " << y << endl;
	Mat& img = * (Mat*) userdata;
	switch (event) {
	case EVENT_MOUSEMOVE:
		if (drawing) {
			g_rect.width = abs(x - downX);
			g_rect.height = abs(y - downY);
			g_rect.x = min(x, downX);
			g_rect.y = min(y, downY);
		}
		break;
	case EVENT_LBUTTONUP:
		drawing = false;
		drawRect(img, g_rect);
		break;
	case EVENT_LBUTTONDOWN:
		downX = x;
		downY = y;
		drawing = true;
		break;
	}
}

void drawRect(Mat& img, Rect& rect) {
	rectangle(img, rect.tl(), rect.br(), Scalar(255,255,255));
}

void MouseDrawTest::mouseDraw() {
	g_rect = Rect(-1, -1, 0, 0);
	Mat srcImg(600, 800, CV_8UC3), tmpImg;
	srcImg.copyTo(tmpImg);
	srcImg = Scalar::all(0);

	namedWindow (WINDOW_NAME);
	// 设置鼠标监听
	setMouseCallback(WINDOW_NAME, mouseChange, (void*) &srcImg);
	while (1) {
		srcImg.copyTo(tmpImg);
		if (drawing) {
			drawRect(tmpImg, g_rect);
		}
		imshow(WINDOW_NAME, tmpImg);
		if (waitKey(10) == 27)
			break; // esc退出
	}

	waitKey(0);
}

MouseDrawTest::~MouseDrawTest() {
}

