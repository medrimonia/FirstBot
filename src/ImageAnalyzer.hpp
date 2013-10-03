#ifndef IMAGE_ANALYZER_HPP
#define IMAGE_ANALYZER_HPP

#include <highgui.h>
#include <cv.h>

class ImageAnalyzer{
private:
  int nbPixels;
  int imageWidth, imageHeight;
  double strength;
  cv::Point center;
  cv::Scalar colorMin;
  cv::Scalar colorMax;
  std::string colorName;

public:
  // Exit if fails to open the device
  ImageAnalyzer(cv::Scalar colorMin,
                cv::Scalar colorMax,
                std::string colorName);

  /* Compute the analysis of the given hsv image */
  void step(cv::Mat hsvImg);

  /* Tag the barycenter on the given frame with the specified color */
  void tag(cv::Mat frame, cv::Scalar tagColor) const;

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
