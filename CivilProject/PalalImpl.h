#pragma once
#include "BaseImpl.h"
class PalalImpl : public BaseImpl
{
public:
  PalalImpl();
  ~PalalImpl(); 
  void setforDiagonal(const Point2d &, const Point2d &); // setFo Tops
  void setforTops(const Point2d &, const Point2d &,
    const Point2d &, const Point2d &);

  Point2d getP1() const;
  Point2d getP2() const;
  Point2d getP3() const;
  Point2d getP4() const;
private:
  Point2d m_Point1;
  Point2d m_Point2;
  Point2d m_Point3;
  Point2d m_Point4;
};