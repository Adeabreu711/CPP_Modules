#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "*WrongCat* Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
	std::cout << "*WrongCat* String Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	std::cout << "*WrongCat* Copy Constructor called" << std::endl;
}
WrongCat::~WrongCat(void)
{
	std::cout << "*WrongCat* Default Destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &cpy)
{
	_type = cpy._type;
	std::cout << "*WrongCat* Copy assignment operator called" << std::endl;
	return (*this);
}
