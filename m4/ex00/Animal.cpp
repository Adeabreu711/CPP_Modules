#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Default Constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "String Constructor called" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	*this = cpy;
	std::cout << "Copy Constructor called" << std::endl;
}
Animal::~Animal(void)
{
	std::cout << "Default Destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal &cpy)
{
	_type = cpy._type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "*" << _type << " sound* " << std::endl;
}
