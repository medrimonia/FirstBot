#ifndef SERIAL_PERSO_H
#define SERIAL_PERSO_H


#include "serialib.h"
#include "Order.hpp"

#define BAUDRATE 115200
#define PORT_SERIE "/dev/ttyUSB0"

class Robot
{
  public:

    Robot();

    void SendCommandMotor(float,float);

    void smoothTransition(const Order & src,
                          const Order & dst);

  private:
    serialib port;
};

#endif
