#include <sstream>
#include <cstdlib>
#include <iostream>

#include "Driver.hpp"

#define DEFAULT_VIDEO_INDEX 0

using namespace std;

int main(int argc, char ** argv){
  int videoIndex = DEFAULT_VIDEO_INDEX;
  if (argc > 1){
    stringstream str(argv[1]);
    str >> videoIndex;
    if (!str){
      cerr << "Invalid video index" << argv[1] << endl;
      exit(EXIT_FAILURE);
    }
  }
  Driver d(videoIndex);
  while(true){
    d.getOrder();
  }
}
