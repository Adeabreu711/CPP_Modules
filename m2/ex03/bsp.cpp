#include "Point.hpp"

Fixed	area(Point const &a, Point const &b, Point const &c)
{
	Fixed area;

	area =  ( a.getX() * (b.getY() - c.getY())
			+ b.getX() * (c.getY() - a.getY())
			+ c.getX() * (a.getY() - b.getY()));

	return (area.abs() / 2.0f);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	sum;
	Fixed	diff;

	sum = area(point, b, c) + area(a, point, c) + area(a, b, point);
	diff =  (sum - area(a, b, c)).abs();

	if (diff >= 0.01f)
		return (false);
	if (area(point, b, c) <= 0.0f  || area(a, point, c) <= 0.0f || area(a, b, point) <= 0.0f)
		return (false);
	return (diff < 0.01f);
}
