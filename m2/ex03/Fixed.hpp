#ifndef FIXED
# define FIXED

#include <iostream>

class Fixed
{
	public :
		Fixed(void);
		Fixed(const int raw);
		Fixed(const float nb);
		Fixed(const Fixed &fixed);
		~Fixed(void);

		Fixed	&operator=(const Fixed &fixed);
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator+(const Fixed &cpy) const;
		Fixed	operator*(const Fixed &cpy) const;
		Fixed	operator/(const Fixed &cpy) const;
		bool	operator!=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	operator++(void);
		Fixed	operator--(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static	Fixed& max(Fixed &f1, Fixed &f2);
		static	Fixed&	min(Fixed &f1, Fixed &f2);
		static const Fixed&	max(const Fixed &f1, const Fixed &f2);
		static const Fixed&	min(const Fixed &f1, const Fixed &f2);

	private :
		int					_rawBits;
		static const int	_fractionalBitsNb = 8;

};

std::ostream &operator<<(std::ostream &os, const Fixed &cpy);

#endif
