#include "IBaseObject.h"

IBaseObject::IBaseObject()
{
  impl = std::make_shared<BaseImpl>();
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
}

void IBaseObject::setName(std::string Name) 
{
}

std::string IBaseObject::getName() const
{
	return std::string();
}
