#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat(void);
		Cat(const std::string &type);
		Cat(const Cat &cpy);
		~Cat(void);

		Cat&	operator=(const Cat &cpy);

		void	makeSound(void);
};

#endif
