#include "PalalImpl.h"

PalalImpl::PalalImpl()
{
  m_Point1 = Point2d(0, 0);
  m_Point2 = Point2d(0, 0);
  m_Point3 = Point2d(0, 0);
  m_Point4 = Point2d(0, 0);
}

PalalImpl::~PalalImpl()
{
}

void PalalImpl::setforDiagonal(const Point2d &P1, const Point2d &P2)
{
  m_Point1 = P1;
  m_Point2 = Point2d(P1.x(), P2.y());
  m_Point3 = P2;
  m_Point4 = Point2d(P2.x(), P1.y());
}

void PalalImpl::setforTops(const Point2d &P1, const Point2d &P2,
  const Point2d &P3, const Point2d &P4)
{
  m_Point1 = P1;
  m_Point2 = P2;
  m_Point3 = P3;
  m_Point4 = P4;
}

Point2d PalalImpl::getP1() const
{
  return m_Point1;
}

Point2d PalalImpl::getP2() const
{
  return m_Point2;
}

Point2d PalalImpl::getP3() const
{
  return m_Point3;
}

Point2d PalalImpl::getP4() const
{
  return m_Point4;
}
