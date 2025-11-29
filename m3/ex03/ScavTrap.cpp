#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_name = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "BrrRrrrR... Inherited Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "BrrRrrrR... Inherited String Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap()
{
	*this = cpy;

	std::cout << "BrrRrrrR... Inherited Copy Constructor called" << std::endl;
}
ScavTrap::~ScavTrap(void)
{
	std::cout << "BrrRrrrR... Inherited Default Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &cpy)
{
	std::cout << "BrrRrrrR... Inherited Copy assignment operator called" << std::endl;
	_name = cpy._name;
	_hitPoints = cpy._hitPoints;
	_energyPoints = cpy._energyPoints;
	_attackDamage = cpy._attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (checkDeath(ATTACK_MSG))
		return ;
	_energyPoints--;
	std::cout 
		<< "ScavTrapt [" << _name << "] attacks with passion "
		<< target << " causing [" << _attackDamage 
		<< "] points of damage !" << std::endl;
}

void		ScavTrap::guardGate(void)
{
	if (checkDeath(""))
		return ;
	std::cout
		<< "ScavTrapt [" << _name <<
		"] is now in gate keeper mode." << std::endl;
}

