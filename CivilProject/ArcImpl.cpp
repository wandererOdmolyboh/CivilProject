#include "ArcImpl.h"

ArcImpl::ArcImpl()
{
   m_dCenter = Point2d(0,0);
   m_dRadius = 0;
   m_dAngle1 = 0;
   m_dAngle2 = 0;
}

ArcImpl::~ArcImpl()
{
}

void ArcImpl::setAllValueArc(const Point2d &center,
  const double radius, const double angleFirst,
  const double angleSecond)
{
  m_dCenter = center;
  m_dRadius = radius;
  m_dAngle1 = angleFirst;
  m_dAngle2 = angleSecond;
}
void ArcImpl::setCenter(const Point2d &center)
{
  m_dCenter;
}

void ArcImpl::setRadiuse(const double radius)
{
  m_dRadius;
}

void ArcImpl::setAngleFirst(const double angleFirst)
{
  m_dAngle1;
}

void ArcImpl::setAngleSecond(const double angleSecond)
{
  m_dAngle2;
}

Point2d ArcImpl::getCenter() const
{
  return m_dCenter;
}

double ArcImpl::getRadiuse() const
{
  return m_dRadius;
}

double ArcImpl::getAngleFirst() const
{
  return m_dAngle1;
}

double ArcImpl::gettAngleSecond() const
{
  return m_dAngle2;
}