#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "*Dog* Default Constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type)
{
	std::cout << "*Dog* String Constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	std::cout << "*Dog* Copy Constructor called" << std::endl;
}
Dog::~Dog(void)
{
	std::cout << "*Dog* Default Destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog &cpy)
{
	_type = cpy._type;
	std::cout << "*Dog* Copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << getType() << ": Baark bark bark !" << std::endl;
}
