#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "*Cat* Default Constructor called" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type)
{
	std::cout << "*Cat* String Constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "*Cat* Copy Constructor called" << std::endl;
}
Cat::~Cat(void)
{
	std::cout << "*Cat* Default Destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat &cpy)
{
	_type = cpy._type;
	std::cout << "*Cat* Copy assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void)
{
	std::cout << getType() << ": Miiiiiiaow miaaaaow !" << std::endl;
}
