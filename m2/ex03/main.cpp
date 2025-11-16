#include <iostream>
#include "Point.hpp"

int	main(void)
{
	Point a(1,3);
	Point b(3,2);
	Point c(1,1);

	Fixed test = area(a, b, c);
	std::cout << test << std::endl;
	return (0);
}
