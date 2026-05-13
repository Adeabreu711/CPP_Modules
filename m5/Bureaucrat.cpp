#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("alde-abr"), _grade(LOWEST_GRADE)
{
	std::cout << "Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Custom Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = cpy;
}

Bureaucrat::~Bureaucrat() throw()
{
	std::cout << "Default Destructor called" << std::endl;
}

