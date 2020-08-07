#include "Arc.h"
#include "ArcImpl.h"

Arc::Arc(): IBaseObject(std::make_shared<ArcImpl>())
{
  d_pImpl->setName("Arc");
}

Arc::~Arc()
{

}

Arc::Arc(const Arc & rhs)
{
  copyFrom(rhs);
}

Arc & Arc::operator=(const Arc & rhs)
{
  d_pImpl.reset();
  copyFrom(rhs);
  return *this;
}

Rect * Arc::boundingBox()
{
  return nullptr;//todo  Rect
}

void Arc::DrawObject(IWDraw *w) const
{
  if (!isValid())
    return;
  std::shared_ptr<ArcImpl> curImpl =
    (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl));
  double angl1 = curImpl->getAngleFirst();// how to formate data?
	double angl2 = curImpl->getAngleSecond(); // how to formate data?
	w->drawText(curImpl->getName().c_str());
	Point2d p1(curImpl->curSegment(angl1));
  Point2d p2;
	for (double i = angl1; i <= angl2; i += ConstValue::StepAngle)
	{
		p2 = (curImpl->curSegment(i));
		w->drawSegment(p1, p2);
		p1 = p2;
	}
	std::cout << "Length of the lines segments" << circumference() << std::endl;
}

bool Arc::isValid() const
{
  if (CompareDoubleLess((boost::dynamic_pointer_cast<ArcImpl>
    (d_pImpl))->getRadiuse(), 0))
      return false;
  return true;
}

double Arc::circumference() const
{
  return (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl))->circumference();
 
}

void Arc::save(IWrite *w)
{
  
  std::shared_ptr<ArcImpl> curImpl =
    (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl));
  w->wrInt(4);
  Point2d t1 = curImpl->getCenter();
  w->wrPoint2(t1);
  double tmp = curImpl->getRadiuse();
  w->wrDouble(tmp);
  tmp = curImpl->getAngleFirst();
  w->wrDouble(tmp);
  tmp = curImpl->getAngleSecond();
  w->wrDouble(tmp);
}

void Arc::load(IRead *r)
{
  std::shared_ptr<ArcImpl> curImpl =
    (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl));
  curImpl->setCenter(r->rdPoint2());
  curImpl->setRadiuse(r->rdDouble());
  curImpl->setAngleFirst(r->rdDouble());
  curImpl->setAngleSecond(r->rdDouble());
}

void Arc::set(const std::vector<double>& tmp)
{
  if (tmp.size() != 5)
  {
    std::cout << "bad size vector" << std::endl;
    return ;
  }
  if (CompareDoubleLess(tmp[2], 0)) // todo compare
  {
    std::cout << "bad radiuse" << std::endl;
    return ;
  }
  (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl))->setAllValueArc(
  Point2d(tmp[0], tmp[1]), tmp[2], tmp[3], tmp[4]);
}

void Arc::set(const Point2d & center, const double radius, 
  const double angleFirst, const double angleSecond)
{
  if (CompareDoubleLess(radius, 0)) // todo compare
  {
    std::cout << "bad radiuse" << std::endl;
    return;
  }
  (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl))->setAllValueArc(
    center, radius, angleFirst, angleSecond);
}

void Arc::copyFrom(const Arc & rhs)
{
  this->d_pImpl = rhs.d_pImpl;
}
