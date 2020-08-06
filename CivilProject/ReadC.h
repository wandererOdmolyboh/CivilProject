#pragma once
#include "IRead.h"
class ReadC : public IRead
{
public:
  ReadC() {};
  virtual ~ReadC() {};
  Point2d rdPoint2();
  int rdInt();
  double rdDouble();
};

