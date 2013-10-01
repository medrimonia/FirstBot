#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "ImageAnalyzer.hpp"

#define COLOR1_MIN cv::Scalar(0,80,80)
#define COLOR1_MAX cv::Scalar(10,255,255)

#define DETAIL_LEVEL 1

using namespace cv;
using namespace std;

ImageAnalyzer::ImageAnalyzer(int cameraId): input(cameraId){
  if (!input.isOpened()){
    cerr << "Cannot open the video file" << endl;
    exit(EXIT_FAILURE);
  }
#if DETAIL_LEVEL > 0
  namedWindow("Video", CV_WINDOW_AUTOSIZE);
  namedWindow("Red", CV_WINDOW_AUTOSIZE);
#endif
#if DETAIL_LEVEL > 1
  namedWindow("HSV", CV_WINDOW_AUTOSIZE);
#endif
  //namedWindow("Canny", CV_WINDOW_AUTOSIZE);
}

void ImageAnalyzer::step(){
  bool captureSuccess = input.read(lastFrame);

  if (!captureSuccess){
    cerr << "Failed to read a frame from the video input" << endl;
    exit(EXIT_FAILURE);
  }
  cvtColor(lastFrame, lastFrameHSV, CV_BGR2HSV);

  cv::Mat color1Img;
	cv::inRange(lastFrameHSV, COLOR1_MIN, COLOR1_MAX, color1Img);

  double totalX(0.0), totalY(0.0);
  nbPixelsColor1 = 0;

  // Computing barycenter
  for (int line = 0; line < color1Img.rows; line++){
    for (int column = 0; column < color1Img.cols; column++){
      if (color1Img.at<uchar>(line, column) == 255){
        totalY += line;
        totalX += column;
        nbPixelsColor1++;
      }
    }
  }

  double avgXColor1 = totalX / nbPixelsColor1;
  double avgYColor1 = totalY / nbPixelsColor1;

  color1Center.x = avgXColor1;
  color1Center.y = avgYColor1;

  cv::circle(lastFrame,
             color1Center,
             10,
             cv::Scalar(255, 0, 0),
             CV_FILLED);

#if DETAIL_LEVEL > 0
  imshow("Video", lastFrame);  
  imshow("Red"  , color1Img);
#endif
#if DETAIL_LEVEL > 1
  imshow("HSV"  , lastFrameHSV);
#endif
}

double ImageAnalyzer::getAzimut() const{
  return (color1Center.x - lastFrame.cols / 2) / (lastFrame.cols / 2);
}

double ImageAnalyzer::getElevation() const{
  return (color1Center.y - lastFrame.rows / 2) / (lastFrame.rows / 2);
}

double ImageAnalyzer::partColored() const{
  return nbPixelsColor1 / (lastFrame.cols * lastFrame.rows);
}
