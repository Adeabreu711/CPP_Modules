#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog(void);
		Dog(const std::string &type);
		Dog(const Dog &cpy);
		~Dog(void);

		Dog&	operator=(const Dog &cpy);

		void	makeSound(void) const;
};

#endif
