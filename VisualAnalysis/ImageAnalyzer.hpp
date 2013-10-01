#ifndef LINE_ANALYZER_HPP
#define LINE_ANALYZER_HPP

#include <highgui.h>

class LineAnalyzer{
private:
  cv::VideoCapture input;
  cv::Mat lastFrame;
  cv::Mat lastFrameHSV;

public:
  // Exit if fails to open the device
  LineAnalyzer(int cameraId);

  void step();
};

#endif//LINE_ANALYZER_HPP
