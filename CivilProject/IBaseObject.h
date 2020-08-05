#pragma once
#include <string>
#include <vector>

class Rect;
class IBaseObject
{
public:
	IBaseObject();
	IBaseObject(std::string name);
	virtual ~IBaseObject();
	IBaseObject(const IBaseObject& obj);
	IBaseObject& operator=(const IBaseObject& rhs);

public:
	virtual Rect* boundingBox() = 0; // insert to another interface
  virtual void DrawObject() const = 0;
  virtual bool isValid() const = 0;
	//
	//virtual void save(IWriter*&) = 0;
	//virtual void load(IReader*&) = 0;
  virtual void set(std::vector<double>& tmp) = 0;
protected:
	void setName(std::string) ;
	std::string getName() const;
protected:
	std::string name;
private:
};

