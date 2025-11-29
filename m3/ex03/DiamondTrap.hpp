#ifndef DIAMONDTRAP
# define DIAMONDTRAP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public :
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &cpy);
		~DiamondTrap(void);

		DiamondTrap&	operator=(const DiamondTrap &cpy);

		void	attack(const std::string& target);
		void	whoAmI(void);

	private :
		std::string _name;
};

#endif
