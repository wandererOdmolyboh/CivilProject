#pragma once
#include "Point2d.h"

class IWDraw
{
public:
  IWDraw() {};
  ~IWDraw() {};
  virtual void drawSegment(const Point2d& p1, const Point2d& p2) const = 0;
  virtual void drawText(const char* text) const = 0;
};

