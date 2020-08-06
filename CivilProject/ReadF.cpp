#include "ReadF.h"

ReadF::ReadF()
{
}

ReadF::~ReadF()
{
  m_ifinfile.close();
}

Point2d ReadF::rdPoint2()
{
  if (m_ifinfile.good() == false)
    throw EndOfFile("");
  Point2d tmp;
  m_ifinfile.read(reinterpret_cast<char *>(&tmp), sizeof(Point2d));
  if (tmp.x() == ConstErrorCode::Throw_err_d
    || tmp.y() == ConstErrorCode::Throw_err_d)
    throw ReadError("");
  return tmp;
}

int ReadF::rdInt()
{
  if (m_ifinfile.good() == false)
    throw EndOfFile("");
  int tmp;
  m_ifinfile.read(reinterpret_cast<char *>(&tmp), sizeof(int));
  if (tmp == ConstErrorCode::Throw_err_i)
    throw ReadError("");
  return tmp;
}

double ReadF::rdDouble()
{
  if (m_ifinfile.good() == false)
    throw EndOfFile("");
  double tmp;
  m_ifinfile.read(reinterpret_cast<char *>(&tmp), sizeof(double));
  if (tmp == ConstErrorCode::Throw_err_d)
    throw ReadError("");
  return tmp;
}

void ReadF::open(std::string name)
{
  const char *tmp_name = name.c_str();

  if (isOpen())
    m_ifinfile.close();
  m_ifinfile.open(tmp_name, std::ios::binary | std::ios::in | std::ios::out);
}

bool ReadF::isOpen()
{
  if (m_ifinfile.is_open())
    return true;
  return false;
}