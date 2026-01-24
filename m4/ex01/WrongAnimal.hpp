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

		const std::string		getType(void) const;
		virtual void			makeSound(void) const;

	protected :
		std::string	_type;
};


#endif
