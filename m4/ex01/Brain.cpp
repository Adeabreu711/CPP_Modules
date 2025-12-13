#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	*this = cpy;
	std::cout << "Brain Copy Constructor called" << std::endl;
}
Brain::~Brain(void)
{
	std::cout << "Brain Default Destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain &cpy)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = cpy._ideas[i];
	std::cout << "Brain Copy assignment operator called" << std::endl;
	return (*this);
}
