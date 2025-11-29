#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "CONSTRUCTOR CALL :" << std::endl;

	DiamondTrap	dftDiamondTrap;
	DiamondTrap	cstDiamondTrap("Koby");
	DiamondTrap	cpyDiamondTrap;

	cpyDiamondTrap = cstDiamondTrap;

	std::cout << std::endl << "ATTACK CALL :" << std::endl;

	dftDiamondTrap.attack("test1");
	cstDiamondTrap.attack("test2");
	cpyDiamondTrap.attack("test3");

	std::cout << std::endl << "TAKE DOMMAGE CALL :" << std::endl;

	dftDiamondTrap.takeDamage(10);
	cstDiamondTrap.takeDamage(5);
	cstDiamondTrap.takeDamage(2);

	std::cout << std::endl << "BE REPAIRED CALL :" << std::endl;

	dftDiamondTrap.beRepaired(5);
	cstDiamondTrap.beRepaired(0);
	cstDiamondTrap.beRepaired(2);

	dftDiamondTrap.whoAmI();

	std::cout << std::endl << "DESTRUCTOR CALL :" << std::endl;
	return (0);
}
