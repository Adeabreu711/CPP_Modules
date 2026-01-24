#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat"), _brainPtr(new Brain())
{
	std::cout << "*Cat* Default Constructor called" << std::endl;
}

Cat::Cat(const std::string &type) : AAnimal(type), _brainPtr(new Brain())
{
	std::cout << "*Cat* String Constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : AAnimal(cpy), _brainPtr(new Brain(*cpy._brainPtr))
{
	std::cout << "*Cat* Copy Constructor called" << std::endl;
}
Cat::~Cat(void)
{
	delete _brainPtr;
	std::cout << "*Cat* Default Destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat &cpy)
{
	std::cout << "*Cat* Copy assignment operator called" << std::endl;
	if (this == &cpy)
		return (*this);
	AAnimal::operator=(cpy);
	delete _brainPtr;
	_brainPtr = new Brain(*cpy._brainPtr);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << getType() << ": Miiiiiiaow miaaaaow !" << std::endl;
}

const Brain&	Cat::getBrain(void)const
{
	return (*_brainPtr);
}
