#include "operation_w_double.h"

bool CompareDoubleMore(double a, double b)
{
  double rez = abs(a - b);
  if (rez > ConstValue::Exp)
    return true;
  return false;
}

bool CompareDoubleLess(double a, double b)
{
  double rez = abs(a - b);
  if (rez < ConstValue::Exp)
    return true;
  return false;
}

bool CompareDoubleEquall(double a, double b)
{
  double rez = abs(a - b);

  if (rez == ConstValue::Exp)////????????? < && >
    return true;
  return false;
}
