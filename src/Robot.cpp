#include "Robot.h"

#include <cstdio>

#define DEBUG

using namespace std;

Robot::Robot()
{
 int error= port.Open("/dev/ttyUSB0",BAUDRATE);

  if(error != 1)
  {
    printf("%d\n",error);
  }
  else 
  {
    printf("Reussi\n");
  }

  char c;
  while( port.Read(&c, 1) <= 0 )
  {
    printf("Attente d'une seconde\n");
    sleep(1);
  }

  printf("Construction terminée\n");
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

