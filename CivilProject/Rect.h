#pragma once
#include "AParallelogram.h"
//todo add opertor = and copy after show
class Rect :
  public AParallelogram
{
public:
  Rect();
  virtual bool isValid() const;
  virtual void save(IWrite *);
};

