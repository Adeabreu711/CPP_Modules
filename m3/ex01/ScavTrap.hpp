#ifndef SCRAVTRAP
# define SCRAVTRAP

#include "ClapTrap.hpp"

# define GUARD_GATE_MSG "he can't guard any gate"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &cpy);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap &cpy);

		void		attack(const std::string& target);
		void		guardGate(void);
	
	private:
		std::string	*options;
};


#endif
