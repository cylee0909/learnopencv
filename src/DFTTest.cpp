//
// Created by cylee on 2017/9/3.
//

#include "DFTTest.h"
#include <opencv2/opencv.hpp>  //头文件

using namespace cv;
using namespace std;

void DFTTest::testDft() {
    Mat rawImg = imread("../cat.jpg", 0);
    imshow("raw", rawImg);
    // 获取优化后的长宽以加速傅里叶变换
    int m = getOptimalDFTSize(rawImg.rows);
    int n = getOptimalDFTSize(rawImg.cols);
    //生成扩边后的图片
    Mat padded;
    copyMakeBorder(rawImg, padded, 0, m-rawImg.rows, 0, n - rawImg.cols, BORDER_CONSTANT, Scalar::all(0));
    // 为傅里叶变换结果分配空间
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};

    Mat complexI;
    merge(planes, 2, complexI);

    cout<<"傅里叶变换前 "<<complexI<<endl;
    // 离散傅里叶变换
    dft(complexI, complexI);
    cout<<"傅里叶变换后 "<<complexI<<endl;
    // 分离结果
    split(complexI, planes);
    cout<<"计算幅值前 p0  "<<planes[0]<<endl;
    cout<<"计算幅值前 p1  "<<planes[1]<<endl;
    //计算幅值矩阵
    magnitude(planes[0], planes[1], planes[0]);
    cout<<"计算幅值后 p0  "<<planes[0]<<endl;

    // 图像增强，显示幅值
    Mat magnituteImg = planes[0];
    magnituteImg += Scalar::all(1);
    log(magnituteImg, magnituteImg);

    cout<<"log变换后 mag  "<<magnituteImg<<endl;


    magnituteImg = magnituteImg(Rect(0,0, magnituteImg.cols & -2, magnituteImg.rows & -2));
    int cx = magnituteImg.cols / 2;
    int cy = magnituteImg.rows / 2;
    Mat q0 = magnituteImg(Rect(0,0,cx, cy));
    Mat q1 = magnituteImg(Rect(cx,0,cx, cy));
    Mat q2 = magnituteImg(Rect(0,cy,cx, cy));
    Mat q3 = magnituteImg(Rect(cx,cy,cx, cy));

    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    normalize(magnituteImg, magnituteImg, 0, 1, NORM_MINMAX);
    cout<<"归一化后 mag  "<<magnituteImg<<endl;
    imshow("幅值图像", magnituteImg);
    waitKey(0);
}
