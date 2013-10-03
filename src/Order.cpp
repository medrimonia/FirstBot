#include "Order.hpp"

#define ALLOWED_DIFF_BY_STEP 0.05
#define STEP_DURATION 0.02

double boundValue(double val, double min, double max){
  if (val > max){
    return max;
  }
  if (val < min){
    return min;
  }
  return val;
}

Order::Order(double lSpeed, double rSpeed): leftSpeed(leftSpeed),
                                            rightSpeed(rightSpeed){
  leftSpeed = boundValue(leftSpeed  , -1.0, 1.0);
  rightSpeed = boundValue(rightSpeed, -1.0, 1.0);
}

void Order::adaptOrder(double rotation){
  leftSpeed -= rotation / 2;
  rightSpeed += rotation / 2;
  // Ensuring that leftSpeed is in bounds but keeping rotation as needed
  if (leftSpeed < -1.0){
    rightSpeed -= (leftSpeed + 1.0);
    leftSpeed = -1.0;
  }
  if (leftSpeed > 1.0){
    rightSpeed -= (leftSpeed - 1.0);
    leftSpeed = 1.0;
  }
  // Ensuring that rightSpeed is in bounds.
  rightSpeed = boundValue(rightSpeed, -1.0, 1.0);
}
