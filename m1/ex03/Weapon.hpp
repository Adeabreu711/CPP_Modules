#ifndef WEAPON
# define WEAPON

#include <iostream>

class Weapon
{
	public :
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		const std::string&	getType(void);
		void		setType(std::string type);
	private :
		std::string	_type;
};

#endif
