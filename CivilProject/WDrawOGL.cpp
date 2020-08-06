#include "WDrawOGL.h"

WDrawOGL::WDrawOGL()
{
}

WDrawOGL::~WDrawOGL()
{
}

void WDrawOGL::drawSegment(const Point2d & p1, const Point2d & p2) const
{
  //glBegin(GL_LINES);
  //  glVertex2f(p1.x(), p1.y());
  //  glVertex2f(p2.x(), p2.y());
  //glEnd();
}

void WDrawOGL::drawText(const char * text) const
{
  std::cout << text << std::endl;
}
