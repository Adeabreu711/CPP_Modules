#include "Template.hpp"

//___________________CONSTRUCTORS___________________

Template::Template(void) :
_var(0)
{
}

Template::Template(int var) : _var(var)
{
}

Template::Template(const Template &cpy)
{
	if (this != &cpy)
		_var = cpy._var;
	*this = cpy;
}

//___________________DESTRUCTORS___________________

Template::~Template(void)
{
}

//____________________OVERLOADS____________________

Template& Template::operator=(const Template &cpy)
{
	return (*this);
}

//_____________________GET/SET_____________________

int	Template::GetVar(void) const
{
	return (_var);
}

//____________________FUNCTIONS____________________
