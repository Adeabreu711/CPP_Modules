#include <iostream>
#include "Point.hpp"

int	main(void)
{
	Point a(1.0f, 3.0f);
	Point b(3.0f ,2.0f);
	Point c(1.0f,1.0f);
	Point point(1.2f, 2.6f);

	Fixed test = area(a, b, c);
	std::cout << bsp(a, b, c, point) << std::endl;
	return (0);
}
