#include "PolylineImpl.h"

PolylineImpl::~PolylineImpl()
{
}

Point2dVec PolylineImpl::getData()
{
  return m_Points;
}

void PolylineImpl::add_newPoints(const Point2d &p)
{
  m_Points.push_back(p);
}

const size_t stepforData = 2;

void PolylineImpl::createDataStream(doubleVec data)
{
  size_t len = data.size();
  m_dConterPoint = len / stepforData;
  for (int i = 0; i < len; i += stepforData)
  {
    add_newPoints(Point2d(data[i], data[i + 1]));
  }
}
