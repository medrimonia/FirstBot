#ifndef IMAGE_ANALYZER_HPP
#define IMAGE_ANALYZER_HPP

#include <highgui.h>
#include <cv.h>

class ImageAnalyzer{
private:
  cv::VideoCapture input;
  cv::Mat lastFrame;
  cv::Mat lastFrameHSV;

  int nbPixelsColor1;
  cv::Point color1Center;

public:
  // Exit if fails to open the device
  ImageAnalyzer(int cameraId);

  void step();

  /* Return a value between -1 and 1 corresponding to the azimut detected
   * color barycenter.
   * 0 -> center
   * - -> left
   * + -> right
   */
  double getAzimut() const;

  /* Return a value between -1 and 1 corresponding to the elevation of the
   * detected color barycenter.
   * 0 -> center
   * - -> down
   * + -> up
   */
  double getElevation() const;

  /* Return a value in [0,1] corresponding to the part of the image with the
   * given color.
   */
  double partColored() const;
};

#endif//IMAGE_ANALYZER_HPP
