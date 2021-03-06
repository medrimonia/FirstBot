#include <sstream>
#include <cstdio>

#include "Driver.hpp"
#include "Robot.h"
#include "Config.hpp"

using namespace std;


/* Swaping smoothly order between -1.0 and 1.0. the period of the signal can
 * be controlled, the frequency of the modifications too.
 */
void progressiveTest(){
  Robot robot;
  double cmd = 0;
  double frequency = 30.0;
  double period = 2.0;
  double deltaStep = 4.0 / (frequency * period);
  while(1){
    robot.SendCommandMotor(cmd,cmd);
    cmd += deltaStep;
    if (cmd > 1.0){
      cmd = 1.0;
      deltaStep = -deltaStep;
    }
    if (cmd < -1.0){
      cmd = -1.0;
      deltaStep = -deltaStep;
    }
    usleep(1000000.0 / frequency);
  }
}

void test()
{
  Robot robot;
  double speed = 0.3;
  while(1)
  {
    robot.SendCommandMotor(-speed, -speed);
    sleep(1);
    robot.SendCommandMotor( speed,  speed);
    sleep(1);
  }
}

int main(int argc, char ** argv)
{
/* TEST mode
  //test();
  progressiveTest();
*/
  config.parseFile("../Config.cfg");
  Driver d(config.getVideoIndex());
  Robot robot;
  Order lastOrder;
  while(true){
    Order wishedOrder = d.getOrder();
    robot.smoothTransition(lastOrder, wishedOrder);
    lastOrder = wishedOrder;
    cout << "Order : [" << wishedOrder.leftSpeed << ","
         << wishedOrder.rightSpeed << "]" << endl;
  }
  return 0;
}
