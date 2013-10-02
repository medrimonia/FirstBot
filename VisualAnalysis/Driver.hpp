#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "VideoAnalyzer.hpp"
#include "Order.hpp"

class Driver{
private:
  VideoAnalyzer analyzer;

public:
  Driver(int videoIndex);

  Order getOrder();
};

#endif//DRIVER_HPP
