#include "Robot.h"

#include <cstdio>

#define DEBUG

#define ALLOWED_DIFF_BY_STEP 0.05
#define STEP_DURATION 0.02

using namespace std;

Robot::Robot()
{
 int error= port.Open("/dev/ttyUSB0",BAUDRATE);

  if(error != 1)
  {
    printf("%d\n",error);
  }
#ifdef DEBUG
  else 
  {
    printf("Reussi\n");
  }
#endif

  char c;
  while( port.Read(&c, 1) <= 0 )
  {
    printf("Attente d'une seconde\n");
    sleep(1);
  }
#ifdef DEBUG
  printf("Construction terminée\n");
#endif
}

void Robot::SendCommandMotor(float motL,float motR)
{
  char leftPWM;
  char leftMode;
  char rightPWM;
  char rightMode;

  char test;
  if(motL <0)
  {
    leftPWM = (char)(-motL*255);
    leftMode = 1; // Pour reculer
  }
  else
  {
    leftPWM = (char)(motL*255);
    leftMode = 0; // Pour avancer
  }

  if(motR <0)
  {
    rightPWM = (char)(-motL*255);
    rightMode = 1; // Pour reculer
  }
  else
  {
    rightPWM = (char)(motL*255);
    rightMode = 0; // Pour avancer
  }
  if (port.WriteChar('$') == -1){
    cerr << "Failed to send $" << endl;
    exit(EXIT_FAILURE);
  }
#ifdef DEBUG
  else{
    cout << "$ sent" << endl;;
    printf("Left Order  : [%d,%d]\n", leftMode , leftPWM);
    printf("Right Order : [%d,%d]\n", rightMode, rightPWM);
  }
#endif

  port.WriteChar(leftMode);
  port.WriteChar(leftPWM);
  port.WriteChar(rightMode);
  port.WriteChar(rightPWM);
}

void Robot::smoothTransition(const Order & src,
                             const Order & dst){
  double leftDiff = dst.leftSpeed - src.leftSpeed;
  double rightDiff = dst.rightSpeed - src.rightSpeed;
  double highestDiff;
  if (abs(leftDiff) < abs(rightDiff)){
    highestDiff = abs(rightDiff);
  }
  else{
    highestDiff = abs(leftDiff);
  }
  int nbSteps = highestDiff / ALLOWED_DIFF_BY_STEP;
  double leftStep = leftDiff / (double)nbSteps;
  double rightStep = rightDiff / (double)nbSteps;
  for (int i = 0; i < nbSteps; i++){
    SendCommandMotor(src.leftSpeed + leftStep * i,
                     src.rightSpeed + rightStep * i);
    usleep(1000 * STEP_DURATION);
  }
}
