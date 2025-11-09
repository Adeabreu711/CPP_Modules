#ifndef HUMAN_A
# define HUMAN_A

#include "Weapon.hpp"

class HumanA
{
	public :
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void		attack(void);
	private :
		HumanA(void);

		std::string	_name;
		Weapon		&_weaponREF;
};

#endif
