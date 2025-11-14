#include "Fixed.hpp"
#include <cmath>

//Fixed RawBits Var Constructor
Fixed::Fixed(const int raw) : _rawBits(raw)
{
	std::cout << "Int constructor called" << std::endl;
}

//Fixed RawBits Var Constructor
Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf((float)nb * (float)(1 << _fractionalBitsNb));
}

//Fixed Default Constructor
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Fixed Copy Constructor
Fixed::Fixed(const Fixed &cpy)
{
	*this = cpy;
	std::cout << "Copy constructor called" << std::endl;
}

//Fixed '=' Assignement Operator Overload
Fixed& Fixed::operator=(const Fixed &cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = cpy.getRawBits();
	return (*this);
}

//Ostream '<<' Assignement Operator Overload
std::ostream &operator<<(std::ostream &os, const Fixed &cpy)
{
	os << cpy.toFloat();
	return (os);
}

//Fixed Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (float)(1 << _fractionalBitsNb));
}

int		Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBitsNb);
}
