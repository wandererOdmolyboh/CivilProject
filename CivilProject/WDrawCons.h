#pragma once
#include "IWDraw.h"

class WDrawCons : public IWDraw
{
  WDrawCons();
  virtual void drawSegment(const Point2d& p1, const Point2d& p2);
  virtual void drawText(const char* text);
};

