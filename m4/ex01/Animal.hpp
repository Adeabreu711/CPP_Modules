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

		const std::string		getType(void) const;
		virtual void			makeSound(void) const;

	protected :
		std::string	_type;
};

#endif
