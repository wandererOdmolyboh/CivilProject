#pragma once
#include <string>
#include <vector>
#include "BaseImpl.h"
#include <memory>
#include <boost/pointer_cast.hpp>
#include <boost/shared_ptr.hpp>
#include "IWDraw.h"
#include "IWrite.h"
#include "IRead.h"

class Rect;
class IBaseObject
{
public:
	IBaseObject();
  IBaseObject(std::shared_ptr<BaseImpl> impl);
	virtual ~IBaseObject();
	IBaseObject(const IBaseObject& obj);
	IBaseObject& operator=(const IBaseObject& rhs);

public:
	virtual Rect* boundingBox() = 0; 
  virtual void DrawObject(IWDraw *w) const = 0;
  virtual bool isValid() const = 0;
	//
	virtual void save(IWrite &) = 0;
	virtual void load(IRead &) = 0;
  virtual void set(const std::vector<double>& tmp) = 0;
  std::string getName() const;

protected:
	void setName(std::string);
  std::shared_ptr<BaseImpl> d_pImpl;
private:

};

