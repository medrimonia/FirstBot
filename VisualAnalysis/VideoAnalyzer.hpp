#ifndef VIDEO_ANALYZER_HPP
#define VIDEO_ANALYZER_HPP

#include <cv.h>
#include "ImageAnalyzer.hpp"

#define MAX_FREQUENCY 10

class VideoAnalyzer{
private:
  cv::VideoCapture input;
  ImageAnalyzer colorDetector;
  timeval lastImageTime;

public:
  VideoAnalyzer(int videoIndex);

  void step();

  void launch();

  bool redObjectSeen();

  double getRedAzimut();
};
#endif//VIDEO_ANALYZER_HPP
