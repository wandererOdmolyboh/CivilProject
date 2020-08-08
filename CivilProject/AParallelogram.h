#pragma once
#include "IBaseObject.h"
#include "PalalImpl.h"

class AParallelogram : public IBaseObject
{
public:
  AParallelogram();
  virtual ~AParallelogram();
  AParallelogram(const AParallelogram& obj);
  AParallelogram& operator=(const AParallelogram& rhs);

public:
  virtual Rect* boundingBox() const = 0;
  virtual void DrawObject(IWDraw *w) const;
  virtual bool isValid() const = 0;
  virtual void save(IWrite *);
  virtual void load(IRead *);
  virtual void set(const doubleVec& tmp);

private: void copyFrom(const AParallelogram& rhs);
         void setforTops(const doubleVec& tmp);
         void setforDiagonal(const doubleVec& tmp);
};

