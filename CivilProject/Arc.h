#pragma once
#include "IBaseObject.h"
class Arc : public IBaseObject
{
public:
  Arc();
  virtual ~Arc();
  Arc(const Arc& obj);
  Arc& operator=(const Arc& rhs);

public:
  virtual Rect* boundingBox();
  virtual void DrawObject(IWDraw *w) const;
  virtual bool isValid() const;
  double circumference() const;
  //virtual void save(IWriter*&) = 0;
  //virtual void load(IReader*&) = 0;
  virtual void set(const std::vector<double>& tmp);
  virtual void set(const Point2d &center, const double radius,
    const double angleFirst, const double angleSecond);
};

