#pragma once

#include <fstream> 
#include "Point2d.h"
#include "Exceptions.h"
#include "Constant_Oda.h"
class IRead
{
public:
  IRead() {};
  virtual ~IRead() {};

  virtual int rdInt() = 0;
  virtual double rdDouble() = 0;
  virtual Point2d rdPoint2() = 0;
};

