//
// Created by cylee on 2017/9/2.
//

#include "MixImg.h"
#include <opencv2/opencv.hpp>  //头文件

using namespace cv;
using namespace std;

int contrast = 80;
int bright = 80;
Mat refImg;

void onParamTrackChange(int, void *data) {
    Mat dstImg;
    refImg.copyTo(dstImg);
    int rows = dstImg.rows;
    int cols = dstImg.cols;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Vec3b &data = dstImg.at<Vec3b>(i, j);
            data[0] = saturate_cast<uchar>(data[0] * contrast * 0.01 + bright);
            data[1] = saturate_cast<uchar>(data[1] * contrast * 0.01 + bright);
            data[2] = saturate_cast<uchar>(data[2] * contrast * 0.01 + bright);
//            cout << data << endl;
        }
    }
    imshow("dst", dstImg);
}

void testChange() {
    Mat rawImg = imread("../img1.jpg");
    imshow("raw", rawImg);
    refImg = rawImg;
    onParamTrackChange(0, 0);
    namedWindow("dst");
    createTrackbar("contrast", "dst", &contrast, 300, onParamTrackChange);
    createTrackbar("bright  ", "dst", &bright, 200, onParamTrackChange);
}

void testSplit() {
    Mat rawImg = imread("../img1.jpg");
    vector<Mat> channels;
    split(rawImg, channels);
    for (int i = 0; i < channels.size(); ++i) {
        imshow("result"+to_string(i), channels.at(i));
    }
}

void testShow() {
    Mat rawImg = imread("../img1.jpg");
    Mat cat = imread("../cat.png");
//    cout << cat.channels() << endl << format(cat, Formatter::FMT_PYTHON);
    Mat mask = imread("../cat.png", 0);
    cout << cat.rows << " " << cat.cols<< endl;
    Mat imgRange = rawImg(CvRect(0, 0, cat.cols, cat.rows));
//    cat.copyTo(imgRange, mask);
    addWeighted(imgRange, 1.0, cat, 0.5, 0, imgRange);
    imshow("result", rawImg);
}

void MixImg::testMix() {
//    testShow();
//    testSplit();
    testChange();
    cvWaitKey(0);
}

