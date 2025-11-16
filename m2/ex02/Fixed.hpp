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
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private :
		int					_rawBits;
		static const int	_fractionalBitsNb = 8;

};

std::ostream &operator<<(std::ostream &os, const Fixed &cpy);

#endif
