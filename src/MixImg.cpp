//
// Created by cylee on 2017/9/2.
//

#include "MixImg.h"
#include <opencv2/opencv.hpp>  //头文件

using namespace cv;
using namespace std;

void MixImg::testMix() {
//    Mat rawImg = imread("../img1.jpg");
    Mat cat = imread("../cat.png", IMREAD_UNCHANGED);
    cout << cat.channels() << endl << format(cat, Formatter::FMT_PYTHON);
//    Mat mask = imread("../cartoon.png", 0);
//    Mat imgRange = rawImg(CvRect(100, 100, cartoon.rows, cartoon.cols));
//    cartoon.copyTo(imgRange, mask);
    imshow("result", cat);
    cvWaitKey(0);
}
