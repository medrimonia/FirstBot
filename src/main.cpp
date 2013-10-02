#include "Robot.h"
#include <cstdio>

void test()
{
  Robot robot;
  while(1)
  {
    robot.SendCommandMotor(-0.01,-0.01);
    sleep(1);
    robot.SendCommandMotor(0.01,0.01);
    sleep(1);
  }
}

int main()
{
  test();
  return 0;
}
