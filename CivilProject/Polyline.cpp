#include "Polyline.h"
#include"Rect.h"
#include "FindBoundigBox.h"
Polyline::Polyline() : IBaseObject(std::make_shared<PolylineImpl>())
{
  d_pImpl->setName("Polyline");
}

Polyline::~Polyline()
{

}

Polyline::Polyline(const Polyline & rhs) : IBaseObject(nullptr)
{
  d_pImpl->setName("Polyline");
  copyFrom(rhs);
}

void Polyline::copyFrom(const Polyline & rhs)
{
  this->d_pImpl = rhs.d_pImpl;
}

Polyline & Polyline::operator=(const Polyline & rhs)
{
  if (this == &rhs)
    return *this;
  d_pImpl.reset();
  copyFrom(rhs);
  return *this;
}

Rect * Polyline::boundingBox() const
{
  Rect *rect = new Rect();
  std::vector<double> rez;
  find_Rect((boost::dynamic_pointer_cast<PolylineImpl>(d_pImpl))->getData(), rez);
  rect->set(rez);
  return (rect);
}

void Polyline::DrawObject(IWDraw *w) const
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
    seg_len += data[i-1].dist(data[i]);
    w->drawSegment(data[i - 1], data[i]);
    data[i - 1].set(data[i].x(), data[i].y());
  }
  std::cout << "length of the lines segments " << seg_len << std::endl;
}

bool Polyline::isValid() const
{
  if ((boost::dynamic_pointer_cast<PolylineImpl>(d_pImpl))
    ->getCounter() > 2)
    return true;
  return false;
}


void Polyline::save(IWrite *w)
{
  if (!w->isOpen())
    throw ReadError("Writer not not available");

  auto impl = (boost::dynamic_pointer_cast<PolylineImpl>(d_pImpl));
  size_t lenData = impl->getCounter();
  if (lenData < 3)
    throw ErorDataFigure("Bad size vector");

  Point2dVec data = impl->getData();
  size_t curData = 0;
  w->wrInt(EBrokenLine);
  w->wrInt((int)lenData);
  while (curData < lenData)
  {
    w->wrPoint2(data[curData++]);
  }
}


void Polyline::load(IRead *r)
{
  if (!r->isOpen())
    throw ReadError("Reder not not available");

  size_t lenData = r->rdInt();
  int tmp = 0;
  auto impl = (boost::dynamic_pointer_cast<PolylineImpl>(d_pImpl));
  impl->clearData();
  while (tmp < lenData)
  {
    impl->addNewPoints(r->rdPoint2());
  }
}

void Polyline::set(const doubleVec& tmp)
{
  size_t sizeData = tmp.size();
  if (sizeData % 2 != 0 && sizeData < 4)
  {
    throw ErorDataFigure("Bad size vector");
  }
 (boost::dynamic_pointer_cast<PolylineImpl>(d_pImpl))->createDataStream(tmp); 
}

