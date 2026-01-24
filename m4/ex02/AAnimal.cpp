#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Animal")
{
	std::cout << "Default Constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type)
{
	std::cout << "String Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &cpy)
{
	*this = cpy;
	std::cout << "Copy Constructor called" << std::endl;
}
AAnimal::~AAnimal(void)
{
	std::cout << "Default Destructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal &cpy)
{
	_type = cpy._type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string	AAnimal::getType(void) const
{
	return (_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "*" << _type << " sound* " << std::endl;
}
