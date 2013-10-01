#include <ctime>
#include <sys/time.h>

#include "VideoAnalyzer.hpp"
#include "Colors.hpp"
#include "Config.hpp"

#define MS_TIME(tv)(tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0)

using namespace cv;
using namespace std;

VideoAnalyzer::VideoAnalyzer(int videoIndex): input(videoIndex),
                                              colorDetector(RED_MIN,
                                                            RED_MAX,
                                                            "Red"){
  if (!input.isOpened()){
    cerr << "Cannot open the video file" << endl;
    exit(EXIT_FAILURE);
  }
  input.set(CV_CAP_PROP_FRAME_WIDTH, FRAME_WIDTH);
  input.set(CV_CAP_PROP_FRAME_HEIGHT, FRAME_HEIGHT);
#if DETAIL_LEVEL >= 1
  namedWindow("TaggedImage", CV_WINDOW_AUTOSIZE);
#endif
}

void VideoAnalyzer::step(){
  cv::Mat frame, frameHSV;
  timeval stepStart, stepEnd, elapsedTime;
  gettimeofday(&stepStart, NULL);
  // Checking if it should wait:
  timersub(&stepStart, &lastImageTime, &elapsedTime);
  double timeToSleep = 1000.0 / MAX_FREQUENCY - MS_TIME(elapsedTime);
  if (timeToSleep > 0){
    waitKey(timeToSleep);
  }
  bool captureSuccess = input.read(frame);
  
  if (!captureSuccess){
    cerr << "Failed to read a frame from the video input" << endl;
    exit(EXIT_FAILURE);
  }
  gettimeofday(&lastImageTime, NULL);
  cvtColor(frame, frameHSV, CV_BGR2HSV);

  colorDetector.step(frameHSV);

#if DETAIL_LEVEL >= 1
  // Tagging
  if (redObjectSeen()){
    colorDetector.tag(frame, Scalar(255, 0, 0));
  }

  imshow("TaggedImage", frame);
#endif

  gettimeofday(&stepEnd, NULL);
  timersub(&stepEnd, &stepStart, &elapsedTime);
  printf("Step Time : %f ms\n", MS_TIME(elapsedTime));
}

void VideoAnalyzer::launch(){
  while(true){
    step();
    waitKey(30);
  }
}


bool VideoAnalyzer::redObjectSeen(){
  return (colorDetector.partColored() > DETECTION_PART_THRESHOLD);
}

double VideoAnalyzer::getRedAzimut(){
  return colorDetector.getAzimut();
}
