#include "PalalImpl.h"

PalalImpl::PalalImpl()
{
  m_P1 = Point2d(0, 0);
  m_P2 = Point2d(0, 0);
  m_P3 = Point2d(0, 0);
  m_P4 = Point2d(0, 0);
}

PalalImpl::~PalalImpl()
{
}

void PalalImpl::set(const Point2d &P1, const Point2d &P2)
{
  m_P1 = P1;
  m_P2 = Point2d(P1.x(), P2.y());
  m_P3 = P2;
  m_P4 = Point2d(P2.x(), P1.y());
}

void PalalImpl::set(const Point2d &P1, const Point2d &P2,
  const Point2d &P3, const Point2d &P4)
{
  m_P1 = P1;
  m_P2 = P2;
  m_P3 = P3;
  m_P4 = P4;
}

Point2d PalalImpl::getP1() const
{
  return m_P1;
}

Point2d PalalImpl::getP2() const
{
  return m_P2;
}

Point2d PalalImpl::getP3() const
{
  return m_P3;
}

Point2d PalalImpl::getP4() const
{
  return m_P4;
}
