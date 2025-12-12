#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{}

Ice::Ice(const Ice &cpy) : AMateria("Ice")
{
	*this = cpy;
}

Ice::~Ice()
{}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
