#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char ** argv){
    VideoCapture cap(1); // open the video camera no. 0

    // If opening has failed, close and end
    if (!cap.isOpened()){
      cout << "Cannot open the video file" << endl;
      return -1;
    }

   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

    cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    namedWindow("MyVideo", CV_WINDOW_AUTOSIZE);

    while (true)
    {
        Mat frame;

        bool captureSuccess = cap.read(frame); // read a new frame from video

        if (!captureSuccess) //if not success, break loop
        {
          cout << "Cannot read a frame from video file" << endl;
          break;
        }
        
        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
          cout << "esc key is pressed by user" << endl;
          break; 
        }
    }
    return 0;
}
