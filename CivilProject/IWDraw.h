#pragma once
#include "Point2d.h"

class IWDraw
{
  IWDraw() {};
  ~IWDraw() {};
  virtual void drawSegment(const Point2d& p1, const Point2d& p2) = 0;
  virtual void drawText(const char* text) = 0;
};

