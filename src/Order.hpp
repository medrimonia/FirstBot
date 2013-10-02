#ifndef ORDER_HPP
#define ORDER_HPP

class Order{
public:
  double leftSpeed, rightSpeed;

  Order(): leftSpeed(0.0), rightSpeed(0.0){};
  Order(double leftSpeed, double rightSpeed);

  /* A positive rotation means turning more left */
  void adaptOrder(double rotation);
};
#endif//ORDER_HPP
