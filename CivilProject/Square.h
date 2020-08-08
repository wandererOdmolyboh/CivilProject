#pragma once
#include "AParallelogram.h"
class Square :
  public AParallelogram
{
  virtual bool isValid() const;
  virtual void save(IWrite *);
  virtual Rect* boundingBox() const;
};

