#include "opencv2/highgui/highgui.hpp"
#include <iostream>

#include "ImageAnalyzer.hpp"

using namespace cv;
using namespace std;

int main(int argc, char ** argv){
  ImageAnalyzer myAnalyzer(1);

  while(true){
    myAnalyzer.step();
    waitKey(30);
  }
}
