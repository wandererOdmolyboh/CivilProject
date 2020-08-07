// CivilProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Arc.h"
#include <iostream>

void foo()
{
  for (int i = 0; i < 100000; ++i)
  {
    double d = i * 2 % 10;
  }
}

int main()
{
  Arc *p = new Arc();

  p->set(Point2d(0, 0), 0.5, 0, 180);
  delete p;
  std::cout << "Hello World!\n";
    int  i = 0;
    foo();
    while (true)
    {
      Arc *p = new Arc();
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
