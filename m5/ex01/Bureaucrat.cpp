#include "Bureaucrat.hpp"
#include "Form.hpp"

//____________________CONSTRUCTORS____________________

Bureaucrat::Bureaucrat() :
_name("dftBureaucrat"),
_grade(LOWEST_GRADE)
{
	//std::cout << "Default Bureaucrat Constructor called [" << _name << "]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) :
_name(name),
_grade(grade)
{
	//std::cout << "Custom Bureaucrat Constructor called [" << _name << "]" << std::endl;
	CheckGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) :
_name(cpy._name),
_grade(cpy._grade)
{
	//std::cout << "Copy Bureaucrat Constructor called [" << _name << "]" << std::endl;
	CheckGrade();
}

//____________________DESTRUCTORS____________________

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Default Bureaucrat Destructor called [" << _name << "]" << std::endl;
}

//____________________OVERLOADS____________________

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	//std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_grade = src.GetGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &cpy)
{
	os << cpy.GetName() << ", bureaucrat grade " << cpy.GetGrade();
	return (os);
}

//____________________GET/SET____________________

size_t	Bureaucrat::GetGrade() const
{
	return (_grade);
}

const std::string	Bureaucrat::GetName() const
{
	return (_name);
}

//____________________FUNCTIONS____________________

void	Bureaucrat::IncrementGrade()
{
	_grade--;
	CheckGrade();
}

void	Bureaucrat::DecrementGrade()
{
	_grade++;
	CheckGrade();
}

void	Bureaucrat::CheckGrade()
{
	if (_grade > LOWEST_GRADE)
		throw (GradeTooLowException());
	else if (_grade < HIGHEST_GRADE)
		throw (GradeTooHighException());
}

void	Bureaucrat::SignForm(Form &form)
{
	try
	{
		form.BeSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << *this << " couldn't sign " << form << ". Reason: " << e.what() << std::endl;
	}
}

//____________________EXEPTIONS____________________

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

