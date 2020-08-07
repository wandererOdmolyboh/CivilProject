#pragma once
#include "BaseImpl.h"
#include <vector>

class PolylineImpl : public BaseImpl
{
public:
  PolylineImpl(){};
  virtual ~PolylineImpl();

  Point2dVec getData();
  void add_newPoints(const Point2d &p);
  void createDataStream(doubleVec data);

private:
  Point2dVec m_Points;
  size_t m_dConterPoint;
};

#pragma once
