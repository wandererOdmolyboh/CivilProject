#pragma once
#include "BaseImpl.h"
#include <vector>

class PolylineImpl : public BaseImpl
{
public:
  PolylineImpl();
  virtual ~PolylineImpl();

  Point2dVec getData();
  size_t getCounter();
  void addNewPoints(const Point2d &p);
  void createDataStream(doubleVec data);
  void clearData();
  double countLSegment(size_t p1, size_t p2);

private:
  Point2dVec m_Points;
  size_t m_dConterPoint;
};

#pragma once
