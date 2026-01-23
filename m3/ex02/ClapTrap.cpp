#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
_name("ClapTrap"),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
_name(name),
_hitPoints(10),
_energyPoints(10),
_attackDamage(0)
{
	std::cout << "String Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = cpy;
}
ClapTrap::~ClapTrap(void)
{
	std::cout << "Default Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_name = cpy._name;
	_hitPoints = cpy._hitPoints;
	_energyPoints = cpy._energyPoints;
	_attackDamage = cpy._attackDamage;
	return (*this);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (checkDeath(TAKE_DMG_MSG))
		return ;
	_hitPoints -= amount;
	std::cout
		<< "ClapTrap [" << _name << "] takes ["
		<< amount << "] points of damage !" << std::endl;
}
void	ClapTrap::attack(const std::string& target)
{
	if (checkDeath(ATTACK_MSG) || checkEnergy(ATTACK_MSG))
		return ;
	_energyPoints--;
	std::cout
		<< "ClapTrap [" << _name << "] attacks "
		<< target << " causing [" << _attackDamage
		<< "] points of damage !" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (checkDeath(BE_REPAIRED_MSG) || checkEnergy(BE_REPAIRED_MSG))
		return ;
	_energyPoints--;
	_hitPoints += amount;
	std::cout
		<< "ClapTrap [" << _name << "] repaired himself and restored ["
		<< amount << "] points of damage !" << std::endl;
}

//[UTILS]_______________________________________________

int	ClapTrap::checkDeath(std::string deathMsg)
{
	if (_hitPoints > 0)
		return (0);
	std::cout
	<< "/!\\ [" << _name << "] is dead, " << deathMsg << std::endl;
	return (1);
}

int	ClapTrap::checkEnergy(std::string missingEnergyMsg)
{
	if (_energyPoints > 0)
		return (0);
	std::cout
	<< "/!\\ [" << _name << "] is out of energy, " << missingEnergyMsg << std::endl;
	return (1);
}
