#include "Circle.h"
#include"ArcImpl.h"
#include"Rect.h"
#include "FindBoundigBox.h"
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
  doubleVec bound;

  std::shared_ptr<ArcImpl> curImpl =
    (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl));
  bound.push_back(curImpl->getCenter().x() + curImpl->getRadiuse());
  bound.push_back(curImpl->getCenter().y() + curImpl->getRadiuse());
  bound.push_back(curImpl->getCenter().x() - curImpl->getRadiuse());
  bound.push_back(curImpl->getCenter().y() - curImpl->getRadiuse());
  Rect *rect = new Rect();
  rect->set(bound);
  return (rect);
  return nullptr;
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
  if (!w->isOpen())
    throw ReadError("Writer not not available");
  std::shared_ptr<ArcImpl> curImpl =
    (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl));
  w->wrInt(ECircle);
  Point2d t1 = curImpl->getCenter();
  w->wrPoint2(t1);
  double tmp = curImpl->getRadiuse();
  w->wrDouble(tmp);
  tmp = curImpl->getAngleFirst();
  w->wrDouble(tmp);
  tmp = curImpl->getAngleSecond();
  w->wrDouble(tmp);
}

void Circle::load(IRead *r)
{
  //impCirc.d_pImpl->getName();
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
