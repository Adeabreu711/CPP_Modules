#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "Character.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria	*_inventory[MAX_MATERIA];
	public:
		MateriaSource();
		~MateriaSource();

		MateriaSource&	operator=(const MateriaSource &cpy);
		void		learnMateria(AMateria *m);
		AMateria*	createMateria(std::string const & type);
};

#endif
