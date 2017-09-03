//
// Created by cylee on 2017/9/1.
//

#include "TestCheckImg.h"
#include <opencv2/opencv.hpp>  //头文件
#include <iostream>

using namespace cv;
using namespace std;

void TestCheckImg::printTest() {
//    Mat img(400, 400, CV_8UC3);
//    cvNamedWindow("window_img");
//    imshow("window_img", img);

    Mat rawImg = imread("../img1.jpg");
    imshow("raw", rawImg);

    Mat dstImg;
//    rawImg.copyTo(dstImg);
//    dstImg.create(rawImg.rows, rawImg.cols, rawImg.type());

    double t1 = static_cast<double>(getTickCount());

    colorReduce3(rawImg, dstImg, 32);
    double t2 = static_cast<double>(getTickCount());
    cout << "总计耗时 ： "<< (t2 - t1) / getTickFrequency() << endl;
    imshow("dstImg", dstImg);
}

void TestCheckImg::colorReduce(cv::Mat &raw, cv::Mat &dst, int div) {
    raw.copyTo(dst);
    int row = dst.rows;
    int col = dst.cols * dst.channels() ;
    for (int i = 0; i < row; ++i) {
        uchar *data = dst.ptr(i);
        for (int j = 0; j < col; ++j) {
            data[j] = data[j] / div * div;
        }
    }
}

/**
 * 使用迭代器
 * @param raw
 * @param dst
 * @param div
 */
void TestCheckImg::colorReduce2(cv::Mat &raw, cv::Mat &dst, int div) {
    raw.copyTo(dst);
    MatIterator_<Vec3b> start = dst.begin<Vec3b>();
    MatIterator_<Vec3b> end = dst.end<Vec3b>();
    for (;start != end; start++) {
        (*start)[0] = (*start)[0] / div * div;
        (*start)[1] = (*start)[1] / div * div;
        (*start)[2] = (*start)[2] / div * div;
    }
}

/**
 * 使用动态地址运算
 * @param raw
 * @param dst
 * @param div
 */
void TestCheckImg::colorReduce3(cv::Mat &raw, cv::Mat &dst, int div) {
    raw.copyTo(dst);
    int row = dst.rows;
    int col = dst.cols;
    for (int i = 0; i <row ; ++i) {
        for (int j = 0; j < col; ++j) {
            Vec3b &cp = dst.at<Vec3b>(i, j);
//            cout << "b "<< static_cast<int>(cp[0])<<" g "<< static_cast<int>(cp[1]) << " r "<< static_cast<int>(cp[2]) << endl;
            cp[0] = cp[0] / div * div + div / 2;
            cp[1] = cp[1] / div * div + div / 2;
            cp[2] = cp[2] / div * div + div / 2;
        }
    }
}
