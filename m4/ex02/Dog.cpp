#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog"), _brainPtr(new Brain())
{
	std::cout << "*Dog* Default Constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : AAnimal(type), _brainPtr(new Brain())
{
	std::cout << "*Dog* String Constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) :AAnimal(cpy), _brainPtr(new Brain(*cpy._brainPtr))
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
	std::cout << "*Dog* Copy assignment operator called" << std::endl;
	if (this == &cpy)
		return (*this);
	AAnimal::operator=(cpy);
	delete _brainPtr;
	_brainPtr = new Brain(*cpy._brainPtr);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << getType() << ": Baark bark bark !" << std::endl;
}

const Brain&	Dog::getBrain(void)const
{
	return (*_brainPtr);
}
