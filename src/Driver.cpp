#include <sstream>
#include <iostream>

#include "Driver.hpp"
#include "Config.hpp"

#define DEBUG

#define UNKNOWN_STATE         0
#define SEARCHING_RED_STATE   1
#define RED_LOCKED            2
#define SEARCHING_GREEN_STATE 3
#define GREEN_LOCKED          4

Driver::Driver(int videoIndex): analyzer(videoIndex){
  state = UNKNOWN_STATE;
}

void Driver::updateState(){
  int newState;
  double redStrength = analyzer.redStrength();
  double greenStrength = analyzer.greenStrength();
  if (redStrength < DETECTION_PART_THRESHOLD &&
      greenStrength < DETECTION_PART_THRESHOLD){
    newState = UNKNOWN_STATE;
  }
  if(redStrength > greenStrength){
    if (abs(analyzer.getRedAzimut()) < ANGLE_THRESHOLD){
      newState = RED_LOCKED;
    }
    else{
      newState = SEARCHING_RED_STATE;
    }
  }
  else{
    if (abs(analyzer.getGreenAzimut()) < ANGLE_THRESHOLD){
      newState = GREEN_LOCKED;
    }
    else{
      newState = SEARCHING_GREEN_STATE;
    }
  }
  // if state has changed, some things must be done.
  if (newState != state){
    acc = 0;
  }
}

Order Driver::getOrder(){
  analyzer.step();
  updateState();
  double error = 0;
  // Computing angle Error
  switch(state){
  case SEARCHING_RED_STATE:
    error = analyzer.getRedAzimut(); break;
  case SEARCHING_GREEN_STATE:
    error = analyzer.getGreenAzimut(); break;
  default: break;
  }

  switch(state){
  case UNKNOWN_STATE: return Order(0,0);//TODO searching
  case RED_LOCKED: return Order(-1,-1);
  case GREEN_LOCKED:
    if (analyzer.greenStrength() < TOO_CLOSE_THRESHOLD){
      return Order(0,0);
    }
    return Order(1,1);
  default:
    if (error * acc < 0){//Opposite sign for acc and error
      acc = 0;
    }
  }
  double directionError = error + acc;
  acc += error / 10;
  return Order(-directionError, directionError);
}
