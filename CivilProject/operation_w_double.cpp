#include "operation_w_double.h"

bool CompareDoubleMore(double a, double b)
{
  double rez = abs(a - b);
  if (rez > ConstValue::Tolerance)
    return true;
  return false;
}

bool CompareDoubleLess(double a, double b)
{
  double rez = a - b;
  if (rez < ConstValue::Tolerance)
    return true;
  return false;
}

bool CompareDoubleEquall(double a, double b)
{
  double rez = abs(a - b);

  if (rez <= ConstValue::Tolerance)////????????? < && >
    return true;
  return false;
}
