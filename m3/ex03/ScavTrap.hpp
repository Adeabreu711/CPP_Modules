#ifndef SCRAVTRAP
# define SCRAVTRAP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &cpy);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap &cpy);

		void		attack(const std::string& target);
		void		guardGate(void);
};

#endif
