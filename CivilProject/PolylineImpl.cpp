#include "PolylineImpl.h"

PolylineImpl::~PolylineImpl()
{
}

PolylineImpl::PolylineImpl()
{
  m_dConterPoint = 0;
}

Point2dVec PolylineImpl::getData()
{
  return m_Points;
}

size_t PolylineImpl::getCounter()
{
  return m_dConterPoint;
}

void PolylineImpl::addNewPoints(const Point2d &p)
{
  m_dConterPoint++;
  m_Points.push_back(p);
}

void PolylineImpl::createDataStream(doubleVec data)
{
  clearData();
  const size_t stepforData = 2;
  size_t len = data.size();
  for (int i = 0; i < len; i += stepforData)
  {
    addNewPoints(Point2d(data[i], data[i + 1]));
  }
}

void PolylineImpl::clearData()
{
  m_Points.clear();
}

double PolylineImpl::countLSegment(size_t p1, size_t p2)
{
  if (p1 >= m_dConterPoint || p2 >= m_dConterPoint)
    return -1; // or delete???
  return m_Points.at(p1).dist(m_Points.at(p2));
}
