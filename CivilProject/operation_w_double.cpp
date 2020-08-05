#include "operation_w_double.h"
#define EXP 0.0002
bool CompareDoubleMore(double a, double b)
{
  double rez = abs(a - b);
  if (rez > EXP)
    return true;
  return false;
}

bool CompareDoubleLess(double a, double b)
{
  double rez = abs(a - b);
  if (rez < EXP)
    return true;
  return false;
}

bool CompareDoubleEquall(double a, double b)
{
  double rez = abs(a - b);
  if (rez == EXP)////????????? < && >
    return true;
  return false;
}
