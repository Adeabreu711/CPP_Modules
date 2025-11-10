#ifndef HARL
# define HARL

#include <iostream>

class Harl
{
	public :
		Harl(void);
		~Harl(void);

		void	complain(std::string level);

	private :
		void	debug(void);
		void	warning(void);
		void	info(void);
		void	error(void);
};

#endif
