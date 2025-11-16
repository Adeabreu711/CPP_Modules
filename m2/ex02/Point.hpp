#ifndef POINT
# define POINT

#include "Fixed.hpp"

class Point
{
	public :
		Point(void);
		Point(const float x, const float y);
		Point(const Point &cpy);
		~Point(void);
		Point	&operator=(const Point &cpy);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private :
		const Fixed	_x;
		const Fixed	_y;

};

std::ostream	&operator<<(std::ostream &os, const Point &cpy);

#endif
