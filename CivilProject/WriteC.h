#pragma once
#include "IWrite.h"
class WriteC :
  public IWrite
{
public:
  WriteC() {};
  virtual ~WriteC() {};
  void wrPoint2(const Point2d &tmp);
  void wrInt(int tmp);
  void wrDouble(double tmp);
};

