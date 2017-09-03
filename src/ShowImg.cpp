//============================================================================
// Name        : TestCpp.cpp
// Author      : cylee
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <opencv2/opencv.hpp>  //头文件
using namespace cv;
//包含cv命名空间
using namespace std;

int showImg() {
	// 【1】读入一张图片，载入图像
	Mat srcImage = imread("img1.jpg");
	// 【2】显示载入的图片
	imshow("【原始图】", srcImage);

//	Mat img = image(Rect(20,20,20,20));

	//进行腐蚀操作
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	//显示效果图
	imshow("【效果图】腐蚀操作", dstImage);
	// 【3】等待任意按键按下
	return 0;
}
