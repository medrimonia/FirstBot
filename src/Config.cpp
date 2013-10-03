#include <fstream>
#include <cstdio>
#include <cstring>

#include "Config.hpp"

#define STR_EQ(x, y) (strcmp(x, y) == 0)

using namespace std;
using namespace cv;

int    Config::videoIndex;
int    Config::detailLevel;
double Config::detectionPartThreshold;
double Config::tooCloseThreshold;
double Config::angleThreshold;
double Config::backwardSpeed;
double Config::forwardSpeed;
double Config::discount;
int    Config::frameWidth; 
int    Config::frameHeight;
Scalar Config::redMin;
Scalar Config::redMax;
Scalar Config::greenMin;
Scalar Config::greenMax;

Config config;

Scalar parseScalar(char * str){
  int hue, sat, val;
  sscanf(str, "(%d,%d,%d)", &hue, &sat, &val);
  return Scalar(hue, sat, val);
}

void Config::parseFile(std::string filename) {
  ifstream configFile(filename.c_str());
  string line;
  char varName[30];
  char varVal[20];

  cout << "Parsing file" << endl;

  if (configFile.is_open()) {
    while (getline(configFile, line)) {
      if (line.length() == 0) {
        continue;
      }
      cout << "Scanning line : '" << line << "'" << endl;

      sscanf(line.c_str(), "%s : %s", varName, varVal);

      cout << "varName : '" << varName << "'" << endl;
      cout << "varVal  : '" << varVal << "'" << endl;


      if (STR_EQ(varName, "DEFAULT_VIDEO_INDEX")) {
        sscanf(varVal, "%d", &videoIndex);
      }
      else if (STR_EQ(varName, "DETAIL_LEVEL")) {
        sscanf(varVal, "%d", &detailLevel);
      }
      else if (STR_EQ(varName, "DETECTION_PART_THRESHOLD")) {
        sscanf(varVal, "%lf", &detectionPartThreshold);
      }
      else if (STR_EQ(varName, "TOO_CLOSE_THRESHOLD")) {
        sscanf(varVal, "%lf", &tooCloseThreshold);
      }
      else if (STR_EQ(varName, "ANGLE_THRESHOLD")) {
        sscanf(varVal, "%lf", &angleThreshold);
      }
      else if (STR_EQ(varName, "BACKWARD_SPEED")) {
        sscanf(varVal, "%lf", &backwardSpeed);
      }
      else if (STR_EQ(varName, "FORWARD_SPEED")) {
        sscanf(varVal, "%lf", &forwardSpeed);
      }
      else if (STR_EQ(varName, "DISCOUNT")) {
        sscanf(varVal, "%lf", &discount);
      }
      else if (STR_EQ(varName, "FRAME_WIDTH")) {
        sscanf(varVal, "%d", &frameWidth);
      }
      else if (STR_EQ(varName, "FRAME_HEIGHT")) {
        sscanf(varVal, "%d", &frameHeight);
      }
      else if (STR_EQ(varName, "RED_MIN")) {
        redMin = parseScalar(varVal);
      }
      else if (STR_EQ(varName, "RED_MAX")) {
        redMax = parseScalar(varVal);
      }
      else if (STR_EQ(varName, "GREEN_MIN")) {
        greenMin = parseScalar(varVal);
      }
      else if (STR_EQ(varName, "GREEN_MAX")) {
        greenMax = parseScalar(varVal);
      }
    }
  }
}

int Config::getVideoIndex() {
  return videoIndex;
}

int Config::getDetailLevel() {
  return detailLevel;
}

double Config::getDetectionPartThreshold() {
  return detectionPartThreshold;
}

double Config::getTooCloseThreshold() {
  return tooCloseThreshold;
}

double Config::getAngleThreshold() {
  return angleThreshold;
}

double Config::getBackwardSpeed() {
  return backwardSpeed;
}

double Config::getForwardSpeed() {
  return forwardSpeed;
}

double Config::getDiscount() {
  return discount;
}

int Config::getFrameWidth() {
  return frameWidth; 
} 

int Config::getFrameHeight() {
  return frameHeight;
}

Scalar Config::getRedMin(){
  return redMin;
}
Scalar Config::getRedMax(){
  return redMax;
}
Scalar Config::getGreenMin(){
  return greenMin;
}
Scalar Config::getGreenMax(){
  return greenMax;
}
