#include "Arc.h"
#include "ArcImpl.h"

Arc::Arc(): IBaseObject(new ArcImpl, name)
{
}

Arc::~Arc()
{
}

Arc::Arc(const Arc & obj)
{
}

Arc & Arc::operator=(const Arc & rhs)
{
  // TODO: insert return statement here
}

Rect * Arc::boundingBox()
{
  return nullptr;
}

void Arc::DrawObject() const
{
}

bool Arc::isValid() const
{
  return false;
}

void Arc::set(std::vector<double>& tmp)
{
}
