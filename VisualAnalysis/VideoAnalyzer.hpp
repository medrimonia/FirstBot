#ifndef VIDEO_ANALYZER_HPP
#define VIDEO_ANALYZER_HPP

#include <cv.h>
#include "ImageAnalyzer.hpp"

class VideoAnalyzer{
private:
  cv::VideoCapture input;
  ImageAnalyzer colorDetector;

public:
  VideoAnalyzer(int videoIndex);

  void step();

  void launch();
};
#endif//VIDEO_ANALYZER_HPP
