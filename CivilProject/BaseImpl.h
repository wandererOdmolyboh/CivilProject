#pragma once
#include <iostream>
#include "Point2d.h"
class BaseImpl
{
  BaseImpl();

  void setName(std::string name);

  std::string getName() const;

private:
  std::string m_dcurName;
};

