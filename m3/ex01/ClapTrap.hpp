#ifndef CLAPTRAP
# define CLAPTRAP

#include <iostream>

# define ATTACK_MSG "he can't be attacked"
# define BE_REPAIRED_MSG "he can't attack"
# define TAKE_DMG_MSG "he can't be repaired"

class ClapTrap
{
	public :
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &cpy);
		virtual ~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap &cpy);

		virtual void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	protected :
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

		int			checkDeath(std::string deathMsg);
		int			checkEnergy(std::string deathMsg);
};


#endif
