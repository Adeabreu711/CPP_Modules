#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public :
		Dog(void);
		Dog(const std::string &type);
		Dog(const Dog &cpy);
		~Dog(void);

		Dog&	operator=(const Dog &cpy);

		const Brain&	getBrain(void)const;
		void			makeSound(void) const;

		private :
			Brain	*_brainPtr;
};

#endif
