#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
	std::cout << "String Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	*this = cpy;
	std::cout << "Copy Constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Default Destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &cpy)
{
	_type = cpy._type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType(void)
{
	return (_type);
}

void	WrongAnimal::makeSound(void)
{
	std::cout << "*Wrong sound* " << std::endl;
}
