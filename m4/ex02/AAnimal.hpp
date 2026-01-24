#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class AAnimal
{
	public :
		AAnimal(void);
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &cpy);
		virtual ~AAnimal(void);

		AAnimal&	operator=(const AAnimal &cpy);

		const std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;

	protected :
		std::string	_type;
};

#endif
