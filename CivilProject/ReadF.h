#pragma once
#include "IRead.h"
class ReadF :
  public IRead
{
public:
  ReadF();
  virtual ~ReadF();

  Point2d rdPoint2();
  int rdInt();
  double rdDouble();
  void open(std::string name);
  virtual bool isOpen() const = 0;

private:
  std::ifstream m_ifinfile;
};

