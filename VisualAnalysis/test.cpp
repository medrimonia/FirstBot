#include <iostream>

#include "VideoAnalyzer.hpp"

using namespace std;

int main(int argc, char ** argv){
  VideoAnalyzer myAnalyzer(1);

  myAnalyzer.launch();
  while(true){
    myAnalyzer.step();
  }
}
