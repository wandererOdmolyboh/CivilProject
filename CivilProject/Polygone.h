#pragma once
#include "Polyline.h"
class Polygone : public Polyline 
{
public:
  Polygone();
  virtual ~Polygone();
  Polygone(const Polygone& obj);
  Polygone& operator=(const Polygone& rhs);

public:
  virtual Rect* boundingBox() const;
  virtual void DrawObject(IWDraw *w) const;
  virtual bool isValid() const;
  virtual void save(IWrite *);
  virtual void load(IRead *);
  virtual void set(const doubleVec& tmp);

private: void copyFrom(const Polygone& rhs);
};

