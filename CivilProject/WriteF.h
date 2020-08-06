#pragma once
#include "IWrite.h"
class WriteF : public IWrite
{
public:
  WriteF();
  virtual ~WriteF();

  void wrPoint2(Point2d &tmp);
  void wrInt(int tmp);
  void wrDouble(double tmp);
  void open(std::string name);
  bool isOpen();
private:
  std::ofstream m_ofoutfile;
};

