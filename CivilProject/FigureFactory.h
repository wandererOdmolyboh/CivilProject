#pragma once
#include "Full_libs.h"

class FigureFactory
{
public:
  virtual IBaseObject* createFigure() = 0;
  ~FigureFactory() {}
};


class ArcFactory : public FigureFactory
{
public:
  IBaseObject* createFigure() {
    return new Arc;
  }
};

class CircleFactory : public FigureFactory
{
public:
  IBaseObject* createFigure() {
    return new Circle;
  }
};


class PolylineFactory : public FigureFactory
{
public:
  IBaseObject* createFigure() {
    return new Polyline;
  }
};

class PolygoneFactory : public FigureFactory
{
public:
  IBaseObject* createFigure() {
    return new Polygone;
  }
};

class RectFactory : public FigureFactory
{
public:
  IBaseObject* createFigure() {
    return new Rect;
  }
};

class SquareFactory : public FigureFactory
{
public:
  IBaseObject* createFigure() {
    return new Square;
  }
};
