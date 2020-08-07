#include "ReadC.h"

Point2d ReadC::rdPoint2()
{
  double x, y;
  std::cout << "intput x. point\n";
  std::cin >> x;
  std::cout << "intput y. point\n";
  std::cin >> y;
  return (Point2d(x, y));
}

int ReadC::rdInt()
{
  int x;
  std::cout << "Put the value int"  << std::endl;
  std::cin >> x;
  return (x);
}

double ReadC::rdDouble()
{
  double x;
  std::cout << "Put the value double "  << std::endl;
  std::cin >> x;
  return (x);
}
bool ReadC::isOpen() const
{
  return true;
}

