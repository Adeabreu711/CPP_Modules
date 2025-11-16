#include "Point.hpp"

Fixed	area(Point const &a, Point const &b, Point const &c)
{
	Fixed area;

	area =  ( a.getX() * (b.getY() - c.getY())
			+ b.getX() * (c.getY() - a.getY())
			+ c.getX() * (a.getY() - b.getY())) * 0.5f;

	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	(void)a;
	(void)b;
	(void)c;
	(void)point;
	return (false);
}
