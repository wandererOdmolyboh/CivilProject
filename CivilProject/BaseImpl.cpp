#include "BaseImpl.h"

BaseImpl::BaseImpl()
{
  m_dcurName = "";
}

void BaseImpl::setName(std::string name)
{
  m_dcurName = name;
}

std::string BaseImpl::getName() const
{
  return m_dcurName;
}
