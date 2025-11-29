#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat(void);
		WrongCat(const std::string &type);
		WrongCat(const WrongCat &cpy);
		~WrongCat(void);

		WrongCat&	operator=(const WrongCat &cpy);
};


#endif
