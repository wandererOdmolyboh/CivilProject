#pragma once
#include "Arc.h"
class Circle : public IBaseObject
{
public:
  Circle();
  virtual ~Circle();
  Circle(const Circle& obj);
  Circle& operator=(const Circle& rhs);

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
private: void copyFrom(const Circle& rhs);

private:
  Arc impCirc;
};

