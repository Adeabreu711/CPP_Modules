#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
		delete _inventory[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &cpy)
{
	if (this == &cpy)
			return (*this);
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		delete _inventory[i];
		if (cpy._inventory[i])
			_inventory[i] = cpy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	AMateria *cpy = m;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = cpy->clone();
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	if (type == "cure")
		return (new Cure());
	else if (type == "ice")
		return (new Ice());
	return (NULL);
}


