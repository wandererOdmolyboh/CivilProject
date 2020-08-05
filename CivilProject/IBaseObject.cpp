#include "IBaseObject.h"

IBaseObject::IBaseObject()
{
  d_pImpl = std::make_shared<BaseImpl>();
}

IBaseObject::IBaseObject(std::shared_ptr<BaseImpl> implnew)
{
  d_pImpl = implnew;
  //d_pImpl.
}



IBaseObject::~IBaseObject()
{
}

IBaseObject::IBaseObject(const IBaseObject& rhs)
{
	*this = rhs;
}

IBaseObject& IBaseObject::operator=(const IBaseObject& rhs)
{
  return *this;
}

void IBaseObject::setName(std::string Name) 
{
}

std::string IBaseObject::getName() const
{
	return std::string();
}
