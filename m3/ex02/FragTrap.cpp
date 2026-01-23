#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "Biouuuuuu *FragTrap* Inherited Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "Biouuuuuu *FragTrap* Inherited String Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap()
{
	*this = cpy;

	std::cout << "Biouuuuuu *FragTrap* Inherited Copy Constructor called" << std::endl;
}
FragTrap::~FragTrap(void)
{
	std::cout << "Biouuuuuu *FragTrap* Inherited Default Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &cpy)
{
	std::cout << "Biouuuuuu *FragTrap* Inherited Copy assignment operator called" << std::endl;
	_name = cpy._name;
	_hitPoints = cpy._hitPoints;
	_energyPoints = cpy._energyPoints;
	_attackDamage = cpy._attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (checkDeath(HIGH_FIVES_MSG))
		return ;
	std::cout << "*FragTrap* [" << _name << "]: HelLo, Do yOuu waNt A hIgh FiVe ?" << std::endl;
}

