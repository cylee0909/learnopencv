/*
 * Main.cpp
 *
 *  Created on: 2017年8月28日
 *      Author: cylee
 */

extern int testVideo();
extern int showImg();
//extern int showTrack();
#include "MouseDrawTest.h"

int main() {
	int result = 0;
//	showImg();

//	testVideo();

//	showTrack();

	MouseDrawTest mouse;
	mouse.mouseDraw();
	return result;
}


