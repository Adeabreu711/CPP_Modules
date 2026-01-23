#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "CONSTRUCTOR CALL :" << std::endl;

	ClapTrap	dftClapTrap;
	ClapTrap	cstClapTrap("Boby");
	ClapTrap	cpyClapTrap;

	cpyClapTrap = cstClapTrap;

	std::cout << std::endl << "ATTACK CALL :" << std::endl;

	dftClapTrap.attack("test1");
	cstClapTrap.attack("test2");
	cpyClapTrap.attack("test3");

	std::cout << std::endl << "TAKE DAMAGE CALL :" << std::endl;

	dftClapTrap.takeDamage(10);
	dftClapTrap.attack("test4");
	cstClapTrap.takeDamage(5);
	cstClapTrap.takeDamage(2);

	std::cout << std::endl << "BE REPAIRED CALL :" << std::endl;

	dftClapTrap.beRepaired(5);
	cstClapTrap.beRepaired(0);
	cstClapTrap.beRepaired(2);

	std::cout << std::endl << "DESTRUCTOR CALL :" << std::endl;
	return (0);
}
