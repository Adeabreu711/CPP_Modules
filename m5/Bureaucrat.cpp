#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{}

Bureaucrat::~Bureaucrat() throw()
{}
const char* Bureaucrat::what() const throw()
{
	if (_grade > 150)
		throw (MSG_GRADETOOLOW);
	if (_grade < 1)
		throw (MSG_GRADETOOHIGH);
}

