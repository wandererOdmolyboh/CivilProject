#pragma once
#include "IWDraw.h"
class WDrawOGL : public IWDraw
{
public:
  WDrawOGL();
  virtual ~WDrawOGL();
  virtual void drawSegment(const Point2d& p1, const Point2d& p2) const;
  virtual void drawText(const char* text) const;
};

