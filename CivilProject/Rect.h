#pragma once
#include "AParallelogram.h"
class Rect :
  public AParallelogram
{
  virtual bool isValid() const;
  virtual void save(IWrite *);
  virtual Rect* boundingBox() const;
};

