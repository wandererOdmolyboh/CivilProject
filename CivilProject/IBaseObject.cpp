#include "IBaseObject.h"

IBaseObject::IBaseObject()
{
	name = "BaseObject";
}

IBaseObject::IBaseObject(std::string name_) : name(name_)
{

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
	if (this != &rhs)
	{
		name.clear();
		name = rhs.name;
	}
	return *this;
}

void IBaseObject::setName(std::string Name) 
{
	name = Name;
}

std::string IBaseObject::getName() const
{
	return std::string();
}
