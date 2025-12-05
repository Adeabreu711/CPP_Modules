#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brainPtr(new Brain())
{
	std::cout << "*Dog* Default Constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type), _brainPtr(new Brain())
{
	std::cout << "*Dog* String Constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy), _brainPtr(new Brain())
{
	std::cout << "*Dog* Copy Constructor called" << std::endl;
}
Dog::~Dog(void)
{
	delete _brainPtr;
	std::cout << "*Dog* Default Destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog &cpy)
{
	_type = cpy._type;
	std::cout << "*Dog* Copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void)
{
	std::cout << getType() << ": Baark bark bark !" << std::endl;
}
