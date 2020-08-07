#include "WriteF.h"
#include "Exceptions.h" 
WriteF::WriteF()
{
}

WriteF::~WriteF()
{
  m_ofoutfile.close();
}

void WriteF::wrInt(int tmp)
{
  if (!isOpen())
    throw ReadError("File not open");
  m_ofoutfile.write(reinterpret_cast<char *>(&tmp), sizeof(int));
}

void WriteF::wrDouble(double tmp)
{
  if (!isOpen())
    throw ReadError("File not open");

  m_ofoutfile.write(reinterpret_cast<char *>(&tmp), sizeof(double));
}

void WriteF::wrPoint2(Point2d &tmp)
{
  if (!isOpen())
    throw ReadError("File not open");
  m_ofoutfile.write(reinterpret_cast<char *>(&tmp), sizeof(Point2d));
}

void WriteF::open(std::string name)
{
  if (isOpen())
    m_ofoutfile.close();
  m_ofoutfile.open(name, std::ios::binary | std::ios::in | std::ios::out);
  if (!m_ofoutfile.is_open())
    m_ofoutfile.open(name, std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
}

bool WriteF::isOpen()
{
  if (m_ofoutfile.is_open())
    return true;
  return false;
}
