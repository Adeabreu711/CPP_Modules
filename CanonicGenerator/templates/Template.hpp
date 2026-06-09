#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <iostream>

class Template
{
	public :
		Template(void);
		Template(const Template &cpy);
		Template(int var);
		~Template(void);

		Template &operator=(const Template &fixed);

		int	GetVar(void) const;

	private :
		int	_var;
};

#endif
