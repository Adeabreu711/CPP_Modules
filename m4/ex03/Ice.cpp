#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice &cpy) : AMateria(cpy)
{}

Ice::~Ice()
{}

Ice&	Ice::operator=(const Ice &cpy)
{
	_type = cpy._type;
	return (*this);
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
