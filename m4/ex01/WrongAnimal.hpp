#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &cpy);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal &cpy);

		std::string		getType(void);
		virtual void	makeSound(void);

	protected :
		std::string	_type;
};


#endif
