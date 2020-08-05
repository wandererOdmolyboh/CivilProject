#include "Arc.h"
#include "ArcImpl.h"

Arc::Arc(): IBaseObject(std::make_shared<ArcImpl>())
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

void Arc::DrawObject(IWDraw *w) const
{
  std::shared_ptr<ArcImpl> curImpl =
    (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl));
  //draw the
}

bool Arc::isValid() const
{
  return false;
}

void Arc::set(std::vector<double>& tmp)
{
  //add to check tmp.size()
  (boost::dynamic_pointer_cast<ArcImpl>(d_pImpl))->setAllValueArc(
  Point2d(tmp[0], tmp[1]), tmp[2], tmp[3], tmp[4]);
}
