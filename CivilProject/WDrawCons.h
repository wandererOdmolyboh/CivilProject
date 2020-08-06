#pragma once
#include "IWDraw.h"

class WDrawCons : public IWDraw
{
public:
  WDrawCons();
  virtual ~WDrawCons();
  virtual void drawSegment(const Point2d& p1, const Point2d& p2) const;
  virtual void drawText(const char* text) const;
};

