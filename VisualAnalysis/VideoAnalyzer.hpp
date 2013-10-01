#ifndef VIDEO_ANALYZER_HPP
#define VIDEO_ANALYZER_HPP

#include <cv.h>
#include "ImageAnalyzer.hpp"

#define MAX_FREQUENCY 10

class VideoAnalyzer{
private:
  cv::VideoCapture input;
  ImageAnalyzer redDetector;
  ImageAnalyzer greenDetector;
  timeval lastImageTime;

public:
  VideoAnalyzer(int videoIndex);

  void step();

  void launch();

  bool redObjectSeen();

  double getRedAzimut();

  bool greenObjectSeen();

  double getGreenAzimut();
};
#endif//VIDEO_ANALYZER_HPP
