#pragma once
#include "IBaseObject.h"
#include "PolylineImpl.h"
class Polygone;
class Polyline : public IBaseObject
{
public:
  Polyline();
  virtual ~Polyline();
  Polyline(const Polyline& obj);
  Polyline& operator=(const Polyline& rhs);

public:
  virtual Rect* boundingBox() const;
  virtual void DrawObject(IWDraw *w) const;
  virtual bool isValid() const;
  virtual void save(IWrite *);
  virtual void load(IRead *);
  virtual void set(const doubleVec& tmp);
 
private: void copyFrom(const Polyline& rhs);
         void save(IWrite *, int Polygone);
         void DrawObjectP(IWDraw *w) const;
         friend Polygone;
};