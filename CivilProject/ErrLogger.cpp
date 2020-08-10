#include "ErrLogger.h"
//todo
void ErrLogger::file_error(int e)
{
  e++;
}

void ErrLogger::data_error(int e)
{
  e++;
}

void ErrLogger::error(int e)
{
  e++;
}

ErrLogger::~ErrLogger()
{

}

ErrLogger & ErrLogger::operator=(const ErrLogger & rhs)
{
  return *this;
}
