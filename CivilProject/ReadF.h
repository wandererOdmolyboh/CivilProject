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
  bool isOpen();

private:
  std::ifstream m_ifinfile;
};

