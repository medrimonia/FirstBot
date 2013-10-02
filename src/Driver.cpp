#include <sstream>
#include <iostream>

#include "Driver.hpp"

Driver::Driver(int videoIndex): analyzer(videoIndex){}

Order Driver::getOrder(){
  analyzer.step();
  if (analyzer.redObjectSeen()){
    double directionError = analyzer.getRedAzimut();
    // First test version, with only proportional reaction
    Order o(directionError, -directionError);
  }
}
