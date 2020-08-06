#include "WriteC.h"

void WriteC::wrPoint2(Point2d & tmp)
{
  std::cout << tmp.x() << " " << tmp.y() << std::endl;
}

void WriteC::wrInt(int tmp)
{
  std::cout << tmp << std::endl;
}

void WriteC::wrDouble(double tmp)
{
  std::cout << tmp << std::endl;
}
