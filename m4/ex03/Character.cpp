#include "Character.hpp"

Character::Character(void) :
_name("Character")
{
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string name) :
_name(name)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &cpy) : _name(cpy._name)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (cpy._inventory[i])
			_inventory[i] = cpy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < MAX_MATERIA; i++)
		delete _inventory[i];
}

Character&	Character::operator=(const Character &cpy)
{
	if (this == &cpy)
		return (*this);
	_name = cpy._name;
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

std::string	const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m->clone();
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if ((idx >= 0 && idx < MAX_MATERIA) && _inventory[idx])
		_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx < MAX_MATERIA) && _inventory[idx])
		_inventory[idx]->use(target);
}

AMateria* const* Character::getInventory() const
{
	return (_inventory);
}

