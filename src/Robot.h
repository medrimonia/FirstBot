#ifndef SERIAL_PERSO_H
#define SERIAL_PERSO_H


#include "serialib.h"

#define BAUDRATE 115200
#define PORT_SERIE "/dev/ttyUSB0"

class Robot
{
  public:

    Robot();

    void SendCommandMotor(float,float);

  private:
    serialib port;
};

#endif
