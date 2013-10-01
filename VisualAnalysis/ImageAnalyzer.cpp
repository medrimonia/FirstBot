#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "ImageAnalyzer.hpp"
#include "Config.hpp"

using namespace cv;
using namespace std;

ImageAnalyzer::ImageAnalyzer(Scalar colorMin,
                             Scalar colorMax,
                             string colorName): colorMin(colorMin),
                                                colorMax(colorMax),
                                                colorName(colorName){
#if DETAIL_LEVEL >= 2
  namedWindow(colorName, CV_WINDOW_AUTOSIZE);
#endif
}

void ImageAnalyzer::step(Mat hsvImg){
  cv::Mat colorImg;
	cv::inRange(hsvImg, colorMin, colorMax, colorImg);
  imageHeight = colorImg.rows;
  imageWidth = colorImg.cols;

  double totalX(0.0), totalY(0.0);
  nbPixels = 0;

  // Computing barycenter
  for (int line = 0; line < colorImg.rows; line++){
    for (int column = 0; column < colorImg.cols; column++){
      if (colorImg.at<uchar>(line, column) == 255){
        totalY += line;
        totalX += column;
        nbPixels++;
      }
    }
  }

  double avgX = totalX / nbPixels;
  double avgY = totalY / nbPixels;

  center.x = avgX;
  center.y = avgY;

#if DETAIL_LEVEL >= 2
  imshow(colorName  , colorImg);
#endif
}

void ImageAnalyzer::tag(Mat frame, Scalar tagColor) const{
  cv::circle(frame,
             center,
             10,
             tagColor,
             CV_FILLED);
}

double ImageAnalyzer::getAzimut() const{
  return (center.x - imageWidth / 2) / (imageWidth / 2.0);
}

double ImageAnalyzer::getElevation() const{
  return (center.y - imageHeight / 2) / (imageHeight / 2.0);
}

double ImageAnalyzer::partColored() const{
  return nbPixels / (double)(imageWidth * imageHeight);
}
