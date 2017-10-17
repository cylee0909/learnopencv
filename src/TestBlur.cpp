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
//    GaussianBlur(rawImg, out, Size(13, 13), 0, 0);

    // 非线性滤波算法
    // 中值滤波
//    medianBlur(rawImg, out, 13);

    // 双边滤波
    bilateralFilter(rawImg, out, 25, 25 * 2, 25 /2);
    imshow("result", out);
}
