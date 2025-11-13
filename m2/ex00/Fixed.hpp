#ifndef FIXED
# define FIXED

#include <iostream>

class Fixed
{
	public :
		Fixed(void);
		Fixed(const Fixed &fixed);
		~Fixed(void);
		Fixed &operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private :
		int					_rawBits;
		static const int	_fractionalBitsNb;

};


#endif
