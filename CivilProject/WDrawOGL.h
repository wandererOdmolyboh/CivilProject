#pragma once
#include "IWDraw.h"
class WDrawOGL : public IWDraw
{
  WDrawOGL();
  virtual void drawSegment(const Point2d& p1, const Point2d& p2);
  virtual void drawText(const char* text);
};

