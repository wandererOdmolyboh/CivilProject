#pragma once

#include <fstream> 
#include "Point2d.h"
#include "Constant_Oda.h"
class IWrite
{
public:
  IWrite() {};
  virtual ~IWrite() {};

  virtual void wrInt(int tmp) = 0;
  virtual void wrDouble(double tmp) = 0;
  virtual void wrPoint2(Point2d &tmp) = 0;
  virtual bool isOpen() const = 0;
};

