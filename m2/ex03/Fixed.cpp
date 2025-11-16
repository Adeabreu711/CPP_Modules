#include "Fixed.hpp"

//Fixed RawBits Var Constructor
Fixed::Fixed(const int raw) : _rawBits(raw)
{}

//Fixed RawBits Var Constructor
Fixed::Fixed(const float nb)
{
	_rawBits = roundf((float)nb * (float)(1 << _fractionalBitsNb));
}

//Fixed Default Constructor
Fixed::Fixed(void) : _rawBits(0)
{}

//Fixed Copy Constructor
Fixed::Fixed(const Fixed &cpy)
{
	*this = cpy;
}

//Fixed '=' Assignement Operator Overload
Fixed& Fixed::operator=(const Fixed &cpy)
{
	_rawBits = cpy.getRawBits();
	return (*this);
}

//Fixed '>' Comparison Operator Overload
bool	Fixed::operator>(const Fixed &other) const
{
	return (_rawBits > other._rawBits);
}

//Fixed '<' Comparison Operator Overload
bool	Fixed::operator<(const Fixed &other) const
{
	return (_rawBits < other._rawBits);
}

//Fixed '>=' Comparison Operator Overload
bool	Fixed::operator>=(const Fixed &other) const
{
	return (_rawBits >= other._rawBits);
}

//Fixed '<=' Comparison Operator Overload
bool	Fixed::operator<=(const Fixed &other) const
{
	return (_rawBits <= other._rawBits);
}

//Fixed '==' Comparison Operator Overload
bool	Fixed::operator==(const Fixed &other) const
{
	return (_rawBits == other._rawBits);
}

//Fixed '!=' Comparison Operator Overload
bool	Fixed::operator!=(const Fixed &other) const
{
	return (_rawBits != other._rawBits);
}

//Fixed '-' Arithmetic Operator Overload
Fixed	Fixed::operator-(const Fixed &cpy) const
{
	Fixed	fixed;
	fixed.setRawBits(_rawBits - cpy.getRawBits());
	return (fixed);
}

//Fixed '+' Arithmetic Operator Overload
Fixed	Fixed::operator+(const Fixed &cpy) const
{
	Fixed	fixed;
	fixed.setRawBits(_rawBits + cpy.getRawBits());
	return (fixed);
}

//Fixed '*' Arithmetic Operator Overload
Fixed	Fixed::operator*(const Fixed &cpy) const
{
	Fixed	fixed;
	fixed.setRawBits((_rawBits * cpy.getRawBits()) >> _fractionalBitsNb);
	return (fixed);
}

//Fixed '/' Arithmetic Operator Overload
Fixed	Fixed::operator/(const Fixed &cpy) const
{
	Fixed	fixed;
	if (!cpy._rawBits)
		return (0);
	fixed.setRawBits((_rawBits << _fractionalBitsNb) / cpy.getRawBits());
	return (fixed);
}

//Fixed '++' Post Increment Operator Overload
Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	_rawBits++;
	return (tmp._rawBits);
}

//Fixed '--' Post Increment Operator Overload
Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	_rawBits--;
	return (tmp._rawBits);
}

//Fixed '++' Pre Increment Operator Overload
Fixed	Fixed::operator++(void)
{
	_rawBits++;
	return (*this);
}

//Fixed '--' Pre Increment Operator Overload
Fixed	Fixed::operator--(void)
{
	_rawBits--;
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
{}

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

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f2 < f1)
		return (f2);
	return (f1);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f2 < f1)
		return (f2);
	return (f1);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f2 > f1)
		return (f2);
	return (f1);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f2 > f1)
		return (f2);
	return (f1);
}

Fixed	Fixed::abs(void) const
{
	if (_rawBits < 0)
		return (-_rawBits);
	return (_rawBits);
}

