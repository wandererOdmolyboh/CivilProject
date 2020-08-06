#pragma once
#include "IWrite.h"
class WriteF : public IWrite
{
public:
  WriteF();
  virtual ~WriteF();

  virtual void wrPoint2(Point2d &tmp);
  virtual void wrInt(int tmp) ;
  virtual void wrDouble(double tmp) ;
  void open(const std::string name);
  bool isOpen();
private:
  std::ofstream m_ofoutfile;
};

