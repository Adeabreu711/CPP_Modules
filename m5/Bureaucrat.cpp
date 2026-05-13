#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is too low";
}

Bureaucrat::Bureaucrat() : _name("alde-abr"), _grade(LOWEST_GRADE)
{
	std::cout << "Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Custom Constructor called" << std::endl;
	CheckGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) : _name(cpy.GetName()), _grade(cpy.GetGrade())
{
	std::cout << "Copy Constructor called" << std::endl;
	CheckGrade();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.GetName() << ", bureaucrat grade " << other.GetGrade() << std::endl;
	return (os);
}

void Bureaucrat::CheckGrade() const
{
	if (_grade > LOWEST_GRADE)
		throw(GradeTooLowException());
	if (_grade < HIGHEST_GRADE)
		throw(GradeTooHighException());
}

const std::string Bureaucrat::GetName() const
{
	return (_name);
}

size_t Bureaucrat::GetGrade() const
{
	return (_grade);
}

void	Bureaucrat::CheckGrade() const
{
	if (_grade > LOWEST_GRADE)
		throw (GradeTooLowException());
	if (_grade < HIGHEST_GRADE)
		throw (GradeTooHighException());
}

void	Bureaucrat::UpGrade()
{
	_grade++;
	CheckGrade();
}

void	Bureaucrat::DownGrade()
{
	_grade--;
	CheckGrade();
}



