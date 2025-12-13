#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

#define MAX_MATERIA 4  

class Character : public ICharacter
{
	protected :
		std::string	_name;
		AMateria	*_inventory[MAX_MATERIA];
	public:
		Character(void);
		Character(const std::string name);
		virtual ~Character();

		Character&	operator=(const Character &cpy);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
