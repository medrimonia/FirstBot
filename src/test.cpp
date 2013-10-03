#include <iostream>

#include "Config.hpp"
#include "VideoAnalyzer.hpp"

using namespace std;

int main(int argc, char ** argv){
  config.parseFile("../Config.cfg");
  VideoAnalyzer myAnalyzer(config.getVideoIndex());

  myAnalyzer.launch();
  while(true){
    myAnalyzer.step();
  }
}
