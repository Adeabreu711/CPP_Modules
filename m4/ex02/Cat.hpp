#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public :
		Cat(void);
		Cat(const std::string &type);
		Cat(const Cat &cpy);
		~Cat(void);

		Cat&	operator=(const Cat &cpy);

		const Brain&	getBrain(void)const;
		void			makeSound(void) const;

	private :
		Brain	*_brainPtr;
};

#endif
