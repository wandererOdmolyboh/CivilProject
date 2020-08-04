#include "Point2d.h"
#include "Point2d.h"
#include <cmath>

Point2d::Point2d() : m_dX(0), m_dY(0)
{

}

Point2d::Point2d(double xx, double yy) : m_dX(xx), m_dY(yy)
{
}

Point2d::~Point2d(void)
{
}


void Point2d::set(double xx, double yy)
{
	m_dX = xx;
	m_dY = yy;
}

void Point2d::setX(double xx)
{
	m_dX = xx;
}

void Point2d::setY(double yy)
{
	m_dY = yy;
}

double Point2d::dist(Point2d& P) const
{
	return sqrt(pow((m_dX - P.x()), 2.0) + pow((m_dY - P.y()), 2.0));
}
