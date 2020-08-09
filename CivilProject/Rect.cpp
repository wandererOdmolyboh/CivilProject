#include "Rect.h"

Rect::Rect() : AParallelogram()
{
}

bool Rect::isValid() const
{
  std::shared_ptr<PalalImpl> curImpl =
    (boost::dynamic_pointer_cast<PalalImpl>(d_pImpl));

  const size_t length_l = 6;
  double L[length_l];

  L[0] = curImpl->getP1().dist(curImpl->getP2());
  L[1] = curImpl->getP1().dist(curImpl->getP3());
  L[2] = curImpl->getP1().dist(curImpl->getP4());
  L[3] = curImpl->getP2().dist(curImpl->getP3());
  L[4] = curImpl->getP2().dist(curImpl->getP4());
  L[5] = curImpl->getP3().dist(curImpl->getP4());
  std::sort(L, L + length_l, std::greater<double>());
  if (CompareDoubleEquall(L[1], L[0]))
    return true;
  return false;
}

void Rect::save(IWrite *w)
{
  w->wrInt(ERect);
  AParallelogram::save(w);
}

Rect * Rect::boundingBox() const
{
  return nullptr;
}
