#include "VideoAnalyzer.hpp"
#include "Colors.hpp"
#include "Config.hpp"

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
  bool captureSuccess = input.read(frame);
  
  if (!captureSuccess){
    cerr << "Failed to read a frame from the video input" << endl;
    exit(EXIT_FAILURE);
  }
  cvtColor(frame, frameHSV, CV_BGR2HSV);

  colorDetector.step(frameHSV);

#if DETAIL_LEVEL >= 1
  // Tagging
  if (colorDetector.partColored() > DETECTION_PART_THRESHOLD){
    colorDetector.tag(frame, Scalar(255, 0, 0));
  }

  imshow("TaggedImage", frame);
#endif
}

void VideoAnalyzer::launch(){
  while(true){
    step();
    waitKey(30);
  }
}
