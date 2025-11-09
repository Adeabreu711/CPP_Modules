#ifndef HUMAN_B
# define HUMAN_B

#include "Weapon.hpp"

class HumanB
{
	public :
		HumanB(std::string name);
		~HumanB(void);

		void		setWeapon(Weapon &weapon);
		void		attack(void);
	private :
		HumanB(void);

		std::string	_name;
		Weapon		*_weaponPTR;
};

#endif
