#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure &cpy) : AMateria("cure")
{
	*this = cpy;
}

Cure::~Cure()
{}

Cure&	Cure::operator=(const Cure &cpy)
{
	_type = cpy._type;
	return (*this);
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
