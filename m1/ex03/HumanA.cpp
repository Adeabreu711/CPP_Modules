#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
_name(name),
_weaponREF(weapon)
{}

HumanA::~HumanA(void)
{}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weaponREF.getType() << std::endl;
}
