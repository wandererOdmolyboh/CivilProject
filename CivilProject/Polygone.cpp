#include "Polygone.h"
#include"Rect.h"
#include "FindBoundigBox.h"
Polygone::Polygone() :  Polyline()
{
  d_pImpl->setName("Polygone");
}

Polygone::~Polygone()
{

}

Polygone::Polygone(const Polygone & rhs) : Polyline()
{
  d_pImpl->setName("Polygone");
  copyFrom(rhs);
}

void Polygone::copyFrom(const Polygone & rhs)
{
  this->d_pImpl = rhs.d_pImpl;
}

Polygone & Polygone::operator=(const Polygone & rhs)
{
  if (this == &rhs)
    return *this;
  d_pImpl.reset();
  copyFrom(rhs);
  return *this;
}

Rect * Polygone::boundingBox() const
{
  return Polyline::boundingBox();
}

bool Polygone::isValid() const
{
  return Polyline::isValid();
}


void Polygone::load(IRead *r)
{
  Polyline::load(r);
}

void Polygone::set(const doubleVec& tmp)
{
  Polyline::set(tmp);
}



void Polygone::save(IWrite *w)
{
  if (!w->isOpen())
    throw ReadError("Writer not not available");

  auto impl = (boost::dynamic_pointer_cast<PolylineImpl>(d_pImpl));
  size_t lenData = impl->getCounter();
  if (lenData < 3)
    throw ErorDataFigure("Bad size vector");
  Point2dVec data = impl->getData();
  size_t curData = 0;
  w->wrInt(EPolygon);
  w->wrInt((int)lenData);
  while (curData < lenData)
  {
    w->wrPoint2(data[curData++]);
  }
}

void Polygone::DrawObject(IWDraw * w) const
{
  if (!isValid())
    throw ErorDataFigure("Figure is not valid cannot draw object");
  auto impl = (boost::dynamic_pointer_cast<PolylineImpl>(d_pImpl));
  Point2dVec data = impl->getData();
  double seg_len = 0.;

  w->drawText(impl->getName().c_str());
  size_t m_dConterPoint = impl->getCounter();
  for (int i = 1; i < m_dConterPoint; i++)
  {
    seg_len += data[i - 1].dist(data[i]);
    w->drawSegment(data[i - 1], data[i]);
    data[i - 1].set(data[i].x(), data[i].y());
  }
  w->drawSegment(data[0], data[m_dConterPoint - 1]);
  seg_len += data[0].dist(data[m_dConterPoint - 1]);
  std::cout << "length of the lines segments " << seg_len << std::endl;
}