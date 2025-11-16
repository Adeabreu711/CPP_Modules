#include "Point.hpp"
#include <cmath>

//Point Default Constructor
Point::Point(void) : _x(0), _y(0)
{}

//Point Var Constructor
Point::Point(const float x, const float y) : _x(x), _y(y)
{}

//Point Copy Constructor
Point::Point(const Point &cpy) : _x(cpy._x), _y(cpy._y)
{}

//Point '=' Assignement Operator Overload
Point&	Point::operator=(const Point &cpy)
{
	(void)cpy;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Point &cpy)
{
	os << "[" << cpy.getX() << ", " <<  cpy.getY() << "]";
	return (os);
}

//Fixed Destructor
Point::~Point(void)
{}

Fixed Point::getX(void) const
{
	return (_x);
}

Fixed Point::getY(void) const
{
	return (_y);
}

