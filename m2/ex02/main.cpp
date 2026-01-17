#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(2);

	std::cout << "a : " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ :" << a++ << std::endl;
	std::cout << "a : " << a << std::endl;

	std::cout << "b : " << b << std::endl << std::endl;

	std::cout << "max : " << Fixed::max( a, b ) << std::endl;
	std::cout << "min : " << Fixed::min( a, b ) << std::endl << std::endl;

	std::cout << "b * c : " << b * c << std::endl;
	std::cout << "b / c : " << b / c << std::endl;
	std::cout << "b + c : " << b + c << std::endl;
	std::cout << "b - c : " << b - c << std::endl << std::endl;

	std::cout << "b > c : " << (b > c) << std::endl;
	std::cout << "b < c : " << (b < c) << std::endl;
	std::cout << "b >= c : " << (b >= c) << std::endl;
	std::cout << "b <= c : " << (b <= c) << std::endl;
	std::cout << "b == c : " << (b == c) << std::endl;
	std::cout << "b == b : " << (b == b) << std::endl;
	std::cout << "b != c : " << (b != c) << std::endl;
	return 0;
}
