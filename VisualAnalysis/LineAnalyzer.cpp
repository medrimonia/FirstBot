#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <cv.h>

#include "LineAnalyzer.hpp"

#define LINE_COLOR_MIN cv::Scalar(0,80,80)
#define LINE_COLOR_MAX cv::Scalar(20,255,255)

using namespace cv;
using namespace std;

LineAnalyzer::LineAnalyzer(int cameraId): input(cameraId){
  if (!input.isOpened()){
    cerr << "Cannot open the video file" << endl;
    exit(EXIT_FAILURE);
  }
  namedWindow("Video", CV_WINDOW_AUTOSIZE);
  namedWindow("LineColor", CV_WINDOW_AUTOSIZE);
  //namedWindow("Canny", CV_WINDOW_AUTOSIZE);
}

void LineAnalyzer::step(){
  bool captureSuccess = input.read(lastFrame);

  if (!captureSuccess){
    cerr << "Failed to read a frame from the video input" << endl;
    exit(EXIT_FAILURE);
  }
  cvtColor(lastFrame, lastFrameHSV, CV_RGB2HSV);

  cv::Mat lineColorImg;
	cv::inRange(lastFrameHSV, LINE_COLOR_MIN, LINE_COLOR_MAX, lineColorImg);
  

  imshow("Video", lastFrame);  
  imshow("LineColor", lineColorImg);  
}
