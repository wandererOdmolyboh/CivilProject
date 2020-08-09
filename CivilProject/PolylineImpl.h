#pragma once
#include "BaseImpl.h"
#include <vector>

class PolylineImpl : public BaseImpl
{
public:
  PolylineImpl();
  virtual ~PolylineImpl();

  std::vector<Point2d> getData();
  size_t getCounter();
  void addNewPoints(const Point2d &p);
  void createDataStream(std::vector<double> data);
  void clearData();
  double countLSegment(size_t p1, size_t p2);

private:
  std::vector<Point2d> m_Points;
  size_t m_dConterPoint;
};

#pragma once
