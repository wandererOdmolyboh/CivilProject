#include "Polygone.h"

Polygone::Polygone() : IBaseObject(std::make_shared<BaseImpl>())
{
  d_pImpl->setName("Polygone");
}

Polygone::~Polygone()
{
}

Polygone::Polygone(const Polygone & rhs) 
  : IBaseObject(std::make_shared<BaseImpl>())
{
  d_pImpl->setName("Polygone");
  copyFrom(rhs);
}

Polygone & Polygone::operator=(const Polygone & rhs)
{
  if (this != &rhs)
  {
    copyFrom(rhs);
  }
  return *this;
}

Rect * Polygone::boundingBox() const
{
  return nullptr;//todo  Rect
}

void Polygone::DrawObject(IWDraw *w) const
{
  if (!isValid())
    throw ErorDataFigure("Figure is not valid cannot draw object");
  impPolygone.DrawObjectP(w);
}

bool Polygone::isValid() const
{
  if (impPolygone.isValid())
    return true;
  return false;
}

void Polygone::save(IWrite *w)
{
  impPolygone.save(w, EPolygon);
}

void Polygone::load(IRead *r)
{
  impPolygone.load(r);
}

void Polygone::set(const doubleVec& tmp)
{
  impPolygone.set(tmp);
}

void Polygone::copyFrom(const Polygone & rhs)
{
  impPolygone = rhs.impPolygone;
}
