#include "Robot.h"

#include <cstdio>


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
  char LeftPWM;
  char LeftMode;
  char RightPWM;
  char RightMode;

  char test;
  if(motL <0)
  {
    LeftPWM = (char)(-motL*255);
    LeftMode = 1; // Pour reculer
  }
  else
  {
    LeftPWM = (char)(motL*255);
    LeftMode = 0; // Pour avancer
  }

  if(motR <0)
  {
    RightPWM = (char)(-motL*255);
    RightMode = 1; // Pour reculer
  }
  else
  {
    RightPWM = (char)(motL*255);
    RightMode = 0; // Pour avancer
  }
  if (port.WriteChar('$') == -1){ printf("Failed to send $\n");}
else{printf("$ sent\n");}

  port.WriteChar(LeftMode);
  port.WriteChar(LeftPWM);
  port.WriteChar(RightMode);
  port.WriteChar(RightPWM);
}

