#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public :
		Intern(void);
		Intern(const Intern &cpy);
		~Intern(void);

		Intern &operator=(const Intern &fixed);

		AForm*	MakeForm(std::string name, std::string target);
};

#endif
