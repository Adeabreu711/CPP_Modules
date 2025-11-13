#include "Fixed.hpp"

//Fixed Default Constructor
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Fixed Copy Constructor
Fixed::Fixed(const Fixed &cpy) : _rawBits(cpy._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

//Fixed '=' Assignement Operator Overload
Fixed& Fixed::operator=(const Fixed &cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = cpy.getRawBits();
	return (*this);
}

//Fixed Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}


