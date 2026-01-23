#ifndef FRAGTRAP
# define FRAGTRAP

#include "ClapTrap.hpp"

# define HIGH_FIVES_MSG "he can't high five"

class FragTrap : public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &cpy);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap &cpy);

		void	highFivesGuys(void);
};


#endif
