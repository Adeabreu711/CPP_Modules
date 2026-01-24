#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public :
		Brain(void);
		Brain(const Brain &cpy);
		~Brain(void);

		Brain&	operator=(const Brain &cpy);

	private :
		std::string	_ideas[100];
};

#endif
