#pragma once
#include <iostream>
#include "Point2d.h"
#include "operation_w_double.h"
#include "EnumEntityType.h"
#include <vector>
typedef std::vector <double> doubleVec;
typedef std::vector<Point2d> Point2dVec;

class BaseImpl
{
public:
  BaseImpl();
  virtual ~BaseImpl();
  void setName(const std::string name);

  std::string getName() const;

private:
  std::string m_dcurName;
  
};

