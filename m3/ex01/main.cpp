#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "CONSTRUCTOR CALL :" << std::endl;

	ScavTrap	dftScavTrap;
	ScavTrap	cstScavTrap("Goby");
	ScavTrap	cpyScavTrap;

	cpyScavTrap = cstScavTrap;

	std::cout << std::endl << "ATTACK CALL :" << std::endl;

	dftScavTrap.attack("test1");
	cstScavTrap.attack("test2");
	cpyScavTrap.attack("test3");

	std::cout << std::endl << "TAKE DOMMAGE CALL :" << std::endl;

	dftScavTrap.takeDamage(10);
	cstScavTrap.takeDamage(5);
	cstScavTrap.takeDamage(2);

	std::cout << std::endl << "BE REPAIRED CALL :" << std::endl;

	dftScavTrap.beRepaired(5);
	cstScavTrap.beRepaired(0);
	cstScavTrap.beRepaired(2);

	dftScavTrap.guardGate();

	std::cout << std::endl << "DESTRUCTOR CALL :" << std::endl;
	return (0);
}
