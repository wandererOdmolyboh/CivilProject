#pragma once
#include "IBaseObject.h"

class  Circle;
class Arc : public IBaseObject
{
public:
  Arc();
  virtual ~Arc();
  Arc(const Arc& obj);
  Arc& operator=(const Arc& rhs);

public:
  virtual Rect* boundingBox() const;
  virtual void DrawObject(IWDraw *w) const;
  virtual bool isValid() const;
  double circumference() const;
  virtual void save(IWrite *);
  virtual void load(IRead *);
  virtual void set(const doubleVec& tmp);
  virtual void set(const Point2d &center, const double radius,
    const double angleFirst, const double angleSecond);
private: void copyFrom(const Arc& rhs);
  friend Circle;
};

