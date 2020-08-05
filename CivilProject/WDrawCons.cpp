#include "WDrawCons.h"


void WDrawCons::drawSegment(const Point2d & p1, const Point2d & p2)
{
  std::cout << p1.x() << " " << p1.y() << " "
    << p2.x() << " " << p2.y() << std::endl;
}

void WDrawCons::drawText(const char * text)
{
  std::cout << text << std::endl;
}
