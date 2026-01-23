#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "CONSTRUCTOR CALL :" << std::endl;

	FragTrap	dftFragTrap;
	FragTrap	cstFragTrap("Loby");
	FragTrap	cpyFragTrap;

	cpyFragTrap = cstFragTrap;

	std::cout << std::endl << "ATTACK CALL :" << std::endl;

	dftFragTrap.attack("test1");
	cstFragTrap.attack("test2");
	cpyFragTrap.attack("test3");

	std::cout << std::endl << "TAKE DAMAGE CALL :" << std::endl;

	dftFragTrap.takeDamage(110);
	cstFragTrap.takeDamage(5);
	cstFragTrap.takeDamage(2);

	std::cout << std::endl << "BE REPAIRED CALL :" << std::endl;

	dftFragTrap.beRepaired(5);
	cstFragTrap.beRepaired(0);
	cstFragTrap.beRepaired(2);

	dftFragTrap.highFivesGuys();

	std::cout << std::endl << "DESTRUCTOR CALL :" << std::endl;
	return (0);
}
