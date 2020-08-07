#pragma once
#include <iostream>

class EndOfFile : public std::exception
{
public:
  EndOfFile(void) = delete;
  ~EndOfFile(void) {}

  EndOfFile(std::string error) : m_error(error)
  {
  }

  const char* what() const noexcept
  {
    return m_error.c_str();
  }
private:
  std::string m_error;
};

class ReadError : public std::exception {

public:
  ReadError(void) = delete;
  ~ReadError(void) {}

  ReadError(std::string error) : m_error(error)
  {
  }

  const char* what() const noexcept
  {
    return m_error.c_str();
  }
private:
  std::string m_error;
};


class ErorDataFigure : public std::exception
{
public:
  ErorDataFigure(void) = delete;
  ~ErorDataFigure(void) {}

  ErorDataFigure(std::string error) : m_error(error)
  {
  }

  const char* what() const noexcept
  {
    return m_error.c_str();
  }
private:
  std::string m_error;
};
