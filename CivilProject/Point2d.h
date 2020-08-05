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
	virtual void set(double xx, double yy);
	virtual void setX(double xx);
	virtual void setY(double yy);
	virtual double dist(Point2d& P) const;
private:
	double m_dX;
	double m_dY;
};

