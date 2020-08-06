#include "Arc.h"
#include "ArcImpl.h"

Arc::Arc(): IBaseObject(std::make_shared<ArcImpl>())
{
}

Arc::~Arc()
{
}

Arc::Arc(const Arc & obj)
{
}

Arc & Arc::operator=(const Arc & rhs)
{
  return *this;
}

Rect * Arc::boundingBox()
{
  return nullptr;
}

void Arc::DrawObject(IWDraw *w) const
{
  std::shared_ptr<ArcImpl> curImpl =
    (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl));
  //draw the

  
  	/*if (!isValid())
		return;
	WDraw w;*/
  double angl1 = curImpl->getAngleFirst();// angl_1;
	double angl2 = curImpl->getAngleSecond(); // angl_2;
	//w.drawText(name.data());
  Point2d center = curImpl->getCenter();
  double radius = curImpl->getRadiuse();

	Point2d p1(center.x() + radius * cos(angl1 * ConstValue::Pi / 180),
    center.y() + radius * sin(angl1 * ConstValue::Pi / 180));
	for (double i = angl1; i < angl2; i += ConstValue::Step)
	{
		Point2d p2(center.x() + radius * cos(i * ConstValue::Pi / 180),
			center.y() + radius * sin(i * ConstValue::Pi / 180));
		w->drawSegment(p1, p2);
		p1.set(p2.x(), p2.y());
	}
	w->drawSegment(p1, Point2d(
		center.x() + radius * cos(angl2 * ConstValue::Pi / 180)
	,
		center.y() + radius * sin(angl2 * ConstValue::Pi / 180)
	));
	std::cout << "Length of the lines segments" << circumference() << std::endl;
  
}

bool Arc::isValid() const
{
  return false;
}

double Arc::circumference() const
{
  return (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl))->circumference();
 
}

void Arc::set(const std::vector<double>& tmp)
{
  //add to check tmp.size()
  (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl))->setAllValueArc(
  Point2d(tmp[0], tmp[1]), tmp[2], tmp[3], tmp[4]);
}

void Arc::set(const Point2d & center, const double radius, 
  const double angleFirst, const double angleSecond)
{
  (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl))->setAllValueArc(
    center, radius, angleFirst, angleSecond);
}
