#pragma once
#include "Full_libs.h"

class FigureFactory
{
public:
  virtual  std::shared_ptr<IBaseObject> createFigure() = 0;
  ~FigureFactory() {}
};


class ArcFactory : public FigureFactory
{
public:
  std::shared_ptr<IBaseObject> createFigure()
  {
    std::shared_ptr<IBaseObject> figure = std::make_shared<Arc>();
    return figure;
  }
};

class CircleFactory : public FigureFactory
{
public:
  std::shared_ptr<IBaseObject> createFigure() {
    std::shared_ptr<IBaseObject> figure = std::make_shared<Circle>();
    return figure;
  }
};


class PolylineFactory : public FigureFactory
{
public:
  std::shared_ptr<IBaseObject> createFigure() {
    std::shared_ptr<IBaseObject> figure = std::make_shared<Polyline>();
    return figure;
  }
};

class PolygoneFactory : public FigureFactory
{
public:
  std::shared_ptr<IBaseObject> createFigure() {
    std::shared_ptr<IBaseObject> figure = std::make_shared<Polygone>();
    return figure;
  }
};

class RectFactory : public FigureFactory
{
public:
  std::shared_ptr<IBaseObject> createFigure() {
    std::shared_ptr<IBaseObject> figure = std::make_shared<Rect>();
    return figure;
  }
};

class SquareFactory : public FigureFactory
{
public:
  std::shared_ptr<IBaseObject> createFigure() {
    std::shared_ptr<IBaseObject> figure = std::make_shared<Square>();
    return figure;
  }
};
