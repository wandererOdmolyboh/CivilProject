#pragma once

#include <iostream>
#include <cmath>

class Point2d
{
public:
	Point2d();
	Point2d(double xx, double yy);
	~Point2d(void); 
	double x() const;
	double y() const;
	void set(double xx, double yy);
	void setX(double xx);
	void setY(double yy);
	double dist(const Point2d& P) const;
private:
	double m_dX;
	double m_dY;
};

