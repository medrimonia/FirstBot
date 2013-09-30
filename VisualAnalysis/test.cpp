#include "opencv2/highgui/highgui.hpp"
#include <iostream>

#include "LineAnalyzer.hpp"

using namespace cv;
using namespace std;

int main(int argc, char ** argv){
  LineAnalyzer myAnalyzer(1);

  while(true){
    myAnalyzer.step();
    waitKey(30);
  }
}
