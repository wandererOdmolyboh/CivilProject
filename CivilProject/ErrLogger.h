#pragma once
class ErrLogger
{
public:
  static void file_error(int e);
  static void data_error(int e);
  static void error(int e);
private:
  ErrLogger();
  ~ErrLogger();
  ErrLogger( const ErrLogger &rhs);
  ErrLogger& operator=(const ErrLogger& rhs);
};

