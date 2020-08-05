#pragma once
#include "IBaseObject.h"
class Arc : public IBaseObject
{
public:
  Arc();
  virtual ~Arc();
  Arc(const Arc& obj);
  Arc& operator=(const Arc& rhs);

public:
  virtual Rect* boundingBox();
  virtual void DrawObject() const;
  virtual bool isValid() const;
  //
  //virtual void save(IWriter*&) = 0;
  //virtual void load(IReader*&) = 0;
  virtual void set(std::vector<double>& tmp);
};

