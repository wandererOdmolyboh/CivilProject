#include "AParallelogram.h"
#include"Rect.h"
#include "FindBoundigBox.h"
AParallelogram::AParallelogram() : 
  IBaseObject(std::make_shared<PalalImpl>())
{
}

AParallelogram::~AParallelogram()
{

}

AParallelogram::AParallelogram(const AParallelogram & rhs) : 
  IBaseObject(std::make_shared<PalalImpl>())
{
  copyFrom(rhs);
}

void AParallelogram::copyFrom(const AParallelogram & rhs)
{
  this->d_pImpl = rhs.d_pImpl;
}

void AParallelogram::setforTops(const doubleVec & tmp)
{
  (boost::dynamic_pointer_cast<PalalImpl>(d_pImpl))->
    setforTops(
      Point2d(tmp.at(0), tmp.at(1)),
      Point2d(tmp.at(2), tmp.at(3)),
      Point2d(tmp.at(4), tmp.at(5)),
      Point2d(tmp.at(6), tmp.at(7))
    );
}

void AParallelogram::setforDiagonal(const doubleVec & tmp)
{
  (boost::dynamic_pointer_cast<PalalImpl>(d_pImpl))->
    setforDiagonal(
      Point2d(tmp.at(0), tmp.at(1)),
      Point2d(tmp.at(2), tmp.at(3))
    );
}
AParallelogram & AParallelogram::operator=(const AParallelogram & rhs)
{
  if (this == &rhs)
    return *this;
  d_pImpl.reset();
  copyFrom(rhs);
  return *this;
}


Rect * AParallelogram::boundingBox() const
{
  auto curImpl =
    (boost::dynamic_pointer_cast<PalalImpl>(d_pImpl));

  Rect *rect = new Rect();
  rect->set(curImpl->getP1(), curImpl->getP2(), curImpl->getP3(), curImpl->getP4());
  return (rect);
}

void AParallelogram::DrawObject(IWDraw *w) const
{
  if (!isValid())
    throw ErorDataFigure("Figure is not valid cannot draw object");
  auto impl = (boost::dynamic_pointer_cast<PalalImpl>(d_pImpl));

  w->drawText(impl->getName().c_str());
  w->drawSegment(impl->getP1(), impl->getP2());
  w->drawSegment(impl->getP2(), impl->getP3());
  w->drawSegment(impl->getP3(), impl->getP4());
  w->drawSegment(impl->getP4(), impl->getP1());

  double seg_len = (impl->getP1()).dist(impl->getP2())
    + impl->getP2().dist(impl->getP3()) + impl->getP3().dist(impl->getP4())
    + impl->getP4().dist(impl->getP1());
  std::cout << "length of the lines segments " << seg_len << std::endl;
}

void AParallelogram::save(IWrite *w)
{
  if (!w->isOpen())
    throw ReadError("Reder not not available");

  auto curImpl =
    (boost::dynamic_pointer_cast<PalalImpl>(d_pImpl));
  Point2d p = curImpl->getP1();
  w->wrPoint2(p);
  p = curImpl->getP2();
  w->wrPoint2(p);
  p = curImpl->getP3();
  w->wrPoint2(p);
  p = curImpl->getP4();
  w->wrPoint2(p);
}

void AParallelogram::load(IRead *r)
{
  if (!r->isOpen())
    throw ReadError("Reder not available");
  auto curImpl =
    (boost::dynamic_pointer_cast<PalalImpl>(d_pImpl));
  curImpl->setforTops(
    r->rdPoint2(), r->rdPoint2(),
    r->rdPoint2(), r->rdPoint2()
  );
 
}

void AParallelogram::set(const doubleVec& tmp)
{
  size_t sizeData = tmp.size();
  if (sizeData == 4)
    setforDiagonal(tmp);
  else if (sizeData == 8)
    setforTops(tmp);
  else
  {
    throw ErorDataFigure("Bad size vector");
  }
}

void AParallelogram::set(const Point2d & P1, const Point2d & P2, const Point2d & P3, const Point2d & P4)
{
  (boost::dynamic_pointer_cast<PalalImpl>(d_pImpl))->setforTops(P1, P2, P3, P4);
}
