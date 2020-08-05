#pragma once
#include <iostream>
#include "Point2d.h"
class BaseImpl
{
public:
  BaseImpl();
  virtual ~BaseImpl();
  void setName(std::string name);

  std::string getName() const;

private:
  std::string m_dcurName;
};

