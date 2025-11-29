#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FragTrap()
{
	_name = "DiamondTrap"; //ICI
	ClapTrap::_name = "DiamondTrap_clap_name"; //ICI
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "*DIAAAAAMOND* Inherited Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "*DIAAAAAMOND* Inherited String Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(), ScavTrap(), FragTrap()
{
	*this = cpy;

	std::cout << "*DIAAAAAMOND* Inherited Copy Constructor called" << std::endl;
}
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "*DIAAAAAMOND* Inherited Default Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &cpy)
{
	std::cout << "*DIAAAAAMOND* Inherited Copy assignment operator called" << std::endl;
	_name = cpy._name;
	_hitPoints = cpy._hitPoints;
	_energyPoints = cpy._energyPoints;
	_attackDamage = cpy._attackDamage;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "HeLlo mY nAme is [" << _name << "] and my ClapTrap name is [" << ClapTrap::_name << "]" << std::endl;
}

