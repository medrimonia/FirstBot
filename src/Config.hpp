#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

class Config;

extern Config config;

class Config {
  private:
    static int videoIndex;
    /* 0 -> No print
     * 1 -> Print tagged image
     * 2 -> Print main analysis
     * 3 -> Print all
     */
    static int detailLevel;
    /* The part of the image corresponding to a color needed to say that an object
     * of this color has been seen.
     */
    static double detectionPartThreshold;

    /* Threshold for stopping when green is locked */
    static double tooCloseThreshold;

    /* The maximal dist to center for an object to be considered as locked
     */
    static double angleThreshold;

    static double backwardSpeed;
    static double forwardSpeed;

    static double discount;

    static int frameWidth; 
    static int frameHeight;

  public:
    Config(){}

    static void parseFile(std::string filename);

    static int getVideoIndex();

    static int getDetailLevel();

    static double getDetectionPartThreshold();

    static double getTooCloseThreshold();

    static double getAngleThreshold();

    static double getBackwardSpeed();
    static double getForwardSpeed();

    static double getDiscount();

    static int getFrameWidth(); 
    static int getFrameHeight();
};

#endif // CONFIG_HPP
