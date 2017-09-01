//
// Created by cylee on 2017/9/1.
//

#ifndef LEARNOPENCV_CVDATATEST_H
#define LEARNOPENCV_CVDATATEST_H


#include <core/mat.hpp>

class TestCheckImg {
public:
    virtual void printTest();

    void colorReduce(cv::Mat &raw, cv::Mat &dst, int i);

    void colorReduce2(cv::Mat &raw, cv::Mat &dst, int div);

    void colorReduce3(cv::Mat &raw, cv::Mat &dst, int div);
};


#endif //LEARNOPENCV_CVDATATEST_H
