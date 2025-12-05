#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public :
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &cpy);
		virtual ~Animal(void);

		Animal&	operator=(const Animal &cpy);

		std::string		getType(void);
		virtual void	makeSound(void) = 0;

	protected :
		std::string	_type;
};

#endif
