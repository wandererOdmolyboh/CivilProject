#pragma once
#include "BaseImpl.h"
class ArcImpl : public BaseImpl
{
public:
  //check the set value???
  void setAllValueArc(Point2d center, double radius, double angleFirst, double angleSecond)
  {
     m_dCenter = center;
     m_dRadius = radius;
     m_dAngle1 = angleFirst;
     m_dAngle2 = angleSecond;
  }
  void setCenter(Point2d center)
  {
    m_dCenter;
  }

  void setRadiuse( double radius)
  {
     m_dRadius;
  }

  void setAngleFirst(double angleFirst)
  {
    m_dAngle1;
  }

  void setAngleSecond( double angleSecond)
  {
    m_dAngle2;
  }

  Point2d getCenter()
  {
    return m_dCenter;
  }

  double getRadiuse()
  {
    return m_dRadius;
  }

  double getAngle1()
  {
    return m_dAngle1;
  }

  double getAngle1()
  {
    return m_dAngle2;
  }

private:
  Point2d m_dCenter;
  double m_dRadius;
  double m_dAngle1;
  double m_dAngle2;
};

