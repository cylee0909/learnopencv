/*
 * Main.cpp
 *
 *  Created on: 2017年8月28日
 *      Author: cylee
 */

//extern int testVideo();
//extern int showImg();
//extern int showTrack();
//#include "MouseDrawTest.h"
//#include "TestCheckImg.h"
#include "MixImg.h"
#include "DFTTest.h"
#include "TestBlur.h"
#include <opencv2/opencv.hpp>  //头文件

int main() {
	int result = 0;
//	showImg();

//	testVideo();

//	showTrack();

//	MouseDrawTest mouse;
//	mouse.mouseDraw();

//	TestCheckImg().printTest();

//	MixImg().testMix();

//	DFTTest().testDft();

    TestBlur().apply();
    cv::waitKey(0);
	return result;
}


