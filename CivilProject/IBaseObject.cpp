#include "IBaseObject.h"

//IBaseObject::IBaseObject()
//{
//  d_pImpl = nullptr;
//  //
//}

IBaseObject::IBaseObject(std::shared_ptr<BaseImpl> implnew)
{
  d_pImpl = implnew;
}



IBaseObject::~IBaseObject()
{
}

IBaseObject::IBaseObject(const IBaseObject& rhs)
{
  copyFrom(rhs);
}

IBaseObject& IBaseObject::operator=(const IBaseObject& rhs)
{
  if (this == &rhs)
    return *this;
  d_pImpl.reset();
  copyFrom(rhs);
  return *this;
}

void IBaseObject::setName(const std::string Name) 
{
  this->d_pImpl->setName(Name);
}

void IBaseObject::copyFrom(const IBaseObject & rhs)
{
  this->d_pImpl = rhs.d_pImpl;
}


std::string IBaseObject::getName() const
{
	return std::string();
}
