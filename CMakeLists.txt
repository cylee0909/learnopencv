cmake_minimum_required(VERSION 3.8)
project(LearnOpencv)

set(CMAKE_CXX_STANDARD 11)
set(OPENCV_INCLUDE_PATH /usr/local/include)
include_directories(
        ${OPENCV_INCLUDE_PATH}
        ${OPENCV_INCLUDE_PATH}/opencv
        ${OPENCV_INCLUDE_PATH}/opencv2
)

#link_directories(
#        /usr/local/lib
#)
#
#find_library(VAR_LIB
#        NAMES
#        libopencv_calib3d
#        libopencv_core
#        libopencv_dnn
#        libopencv_features2d
#        libopencv_flann
#        libopencv_highgui
#        libopencv_imgcodecs
#        libopencv_imgproc
#        libopencv_ml
#        libopencv_objdetect
#        libopencv_photo
#        libopencv_shape
#        libopencv_stitching
#        libopencv_superres
#        libopencv_video
#        libopencv_videoio
#        libopencv_videostab
#        PATHS /usr/local/lib)

set(SOURCE_FILES
        src/Main.cpp
        src/MouseDrawTest.cpp
        src/MouseDrawTest.h
        src/ShowImg.cpp
        src/ShowTrack.cpp
        src/TestVideo.cpp
        img1.jpg)

add_executable(LearnOpencv ${SOURCE_FILES})
find_package(opencv REQUIRED)
target_link_libraries(LearnOpencv ${OpenCV_LIBS})