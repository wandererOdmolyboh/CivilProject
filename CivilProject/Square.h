#pragma once
#include "AParallelogram.h"
//todo add opertor = and copy after show
class Square :
  public AParallelogram
{
  virtual bool isValid() const;
  virtual void save(IWrite *);
};

