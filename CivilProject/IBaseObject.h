#pragma once
#include <string>
#include <vector>
#include <memory>
#include <boost/pointer_cast.hpp>
#include <boost/shared_ptr.hpp>
#include "BaseImpl.h"
#include "IWDraw.h"
#include "IWrite.h"
#include "IRead.h"

class Rect;

class IBaseObject
{
protected:
  IBaseObject(std::shared_ptr<BaseImpl> impl);
public:
	//IBaseObject();
	virtual ~IBaseObject();
	IBaseObject(const IBaseObject& obj);
	IBaseObject& operator=(const IBaseObject& rhs);

public:
	virtual Rect* boundingBox() const = 0; 
  virtual void DrawObject(IWDraw *w) const = 0;
  virtual bool isValid() const = 0;
	
	virtual void save(IWrite *) = 0;
	virtual void load(IRead *) = 0;
  virtual void set(const doubleVec& tmp) = 0;
  std::string getName() const;

protected:
	void setName(const std::string);
  std::shared_ptr<BaseImpl> d_pImpl;
private:
 void copyFrom(const IBaseObject& rhs);

};

