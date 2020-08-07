#include "BaseImpl.h"

BaseImpl::BaseImpl()
{
  m_dcurName = "";
}

BaseImpl::~BaseImpl()
{
}

void BaseImpl::setName(const std::string name)
{
  m_dcurName = name;
}

std::string BaseImpl::getName() const
{
  return m_dcurName;
}
