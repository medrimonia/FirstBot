#ifndef ORDER_HPP
#define ORDER_HPP

class Order{
private:
  double leftSpeed, rightSpeed;

public:
  Order(double leftSpeed, double rightSpeed);

  /* A positive rotation means turning more left */
  void adaptOrder(double rotation);
};
#endif//ORDER_HPP
