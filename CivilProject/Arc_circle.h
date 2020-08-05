#pragma once
#include "IBaseObject.h"
class Arc_circle : public IBaseObject
{
public:
  Arc_circle();
  Arc_circle(std::string name);
  virtual ~Arc_circle();
  Arc_circle(const Arc_circle& obj);
  Arc_circle& operator=(const Arc_circle& rhs);

public:
  virtual Rect* boundingBox();
  virtual void DrawObject() const;
  virtual bool isValid() const;
  //
  //virtual void save(IWriter*&) = 0;
  //virtual void load(IReader*&) = 0;
  virtual void set(std::vector<double>& tmp);
};

