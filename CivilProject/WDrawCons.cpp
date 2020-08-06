#include "WDrawCons.h"


WDrawCons::~WDrawCons()
{
}

void WDrawCons::drawSegment(const Point2d & p1, const Point2d & p2) const
{
  std::cout << p1.x() << " " << p1.y() << " "
    << p2.x() << " " << p2.y() << std::endl;
}

void WDrawCons::drawText(const char * text) const
{
  std::cout << text << std::endl;
}
