// CivilProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Arc.h"
#include <iostream>

#include "FigureFactory.h"


IBaseObject* CreteFindFigure(int type)
{
  IBaseObject* retFigure = nullptr;

  if (type == EArc)
  {
    ArcFactory *ArcF = new ArcFactory();
    retFigure = ArcF->createFigure();
    delete ArcF;
  }
  else if (type == ECircle)
  {
    CircleFactory *CircF = new CircleFactory();
    retFigure = CircF->createFigure();
    delete CircF;
  }
  else if (type == ERect)
  {
    RectFactory *RectF = new RectFactory();
    retFigure = RectF->createFigure();
    delete RectF;
  }
  else if (type == ESquare)
  {
    SquareFactory *SquarF = new SquareFactory();
    retFigure = SquarF->createFigure();
    delete SquarF;

  }
  else if (type == EBrokenLine)
  {
    PolylineFactory *PolynF = new PolylineFactory();
    retFigure = PolynF->createFigure();
    delete PolynF;
  }
  else if (type == EPolygon)
  {
    PolygoneFactory *PolygF = new PolygoneFactory();
    retFigure = PolygF->createFigure();
    delete PolygF;
  }
  return (retFigure);
}


int main()
{
  Arc *p = new Arc();

  p->set(Point2d(0, 0), 0.5, 0, 180);
  delete p;
  std::cout << "Hello World!\n";
    int  i = 0;
    //foo();
    while (true)
    {
      if (i == 1000)
        break;
      i++;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
