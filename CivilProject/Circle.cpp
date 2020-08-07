#include "Circle.h"
Circle::Circle() : IBaseObject(std::make_shared<BaseImpl>())
{
  d_pImpl->setName("Circle");
}

Circle::~Circle()
{
}

Circle::Circle(const Circle & rhs) : IBaseObject(std::make_shared<BaseImpl>())
{
  copyFrom(rhs);
}

Circle & Circle::operator=(const Circle & rhs)
{
  if (this == &rhs)
    return *this;
  copyFrom(rhs);
  return *this;
}

Rect * Circle::boundingBox() const
{
  return nullptr;//todo  Rect
}

void Circle::DrawObject(IWDraw *w) const
{
  if (!isValid())
    throw ErorDataFigure("Figure is not valid cannot draw object");
  impCirc.DrawObject(w);
  std::cout << "Length of the lines segments" << circumference() << std::endl;
}

bool Circle::isValid() const
{
  if (impCirc.isValid())
    return true;
  return false;
}

double Circle::circumference() const
{
  return impCirc.circumference();
}

void Circle::save(IWrite *w)
{
      impCirc.save(w);
}

void Circle::load(IRead *r)
{
  impCirc.load(r);
}

void Circle::set(const doubleVec& tmp)
{ 
  impCirc.set(tmp);
}

void Circle::set(const Point2d & center, const double radius,
  const double angleFirst, const double angleSecond)
{
  impCirc.set(center, radius, angleFirst, angleSecond);
}

void Circle::copyFrom(const Circle & rhs)
{
  d_pImpl->setName("Circle");
  impCirc = rhs.impCirc;
}
