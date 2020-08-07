#pragma once
#include "IBaseObject.h"
class Polyline :
  public IBaseObject
{
public:
  Polyline();
  virtual ~Polyline();
  Polyline(const Polyline& obj);
  Polyline& operator=(const Polyline& rhs);

public:
  virtual Rect* boundingBox() const;
  virtual void DrawObject(IWDraw *w) const;
  virtual bool isValid() const;
  double circumference() const;
  virtual void save(IWrite *);
  virtual void load(IRead *);
  virtual void set(const std::vector<double>& tmp);
  virtual void set(const Point2d &center, const double radius,
    const double angleFirst, const double angleSecond);
private: void copyFrom(const Polyline& rhs);
};