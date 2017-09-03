//
// Created by cylee on 2017/9/4.
//

#include "TestBlur.h"
#include <opencv2/opencv.hpp>  //头文件

using namespace cv;
using namespace std;

void TestBlur::apply() {
    Mat rawImg = imread("../img1.jpg");
    imshow("raw", rawImg);

    Mat out;
    //方框滤波
//    boxFilter(rawImg, out, -1, Size(3, 3));

    // 均值滤波
//    blur(rawImg, out, Size(3, 3));

    // 高斯滤波
    GaussianBlur(rawImg, out, Size(3, 3), 0, 0);
    imshow("result", out);
}
