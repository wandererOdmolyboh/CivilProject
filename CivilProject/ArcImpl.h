#pragma once
#include "BaseImpl.h"

class ArcImpl : public BaseImpl
{
public:
  ArcImpl();
  virtual ~ArcImpl();
  //check the set value???
  void setAllValueArc(const Point2d &center,
    const double radius, const double angleFirst,
    const double angleSecond);
  void setCenter(const Point2d &center);
  void setRadiuse(const double radius);

  void setAngleFirst(const double angleFirst);

  void setAngleSecond(const double angleSecond);

  Point2d getCenter() const;

  double getRadiuse() const;

  double getAngleFirst() const;

  double getAngleSecond() const;
  bool isValid() const;
  double circumference() const;

private:
  Point2d m_dCenter;
  double m_dRadius;
  double m_dAngle1;
  double m_dAngle2;
  double m_dcmfer;
};

