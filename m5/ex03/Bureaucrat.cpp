#include "Bureaucrat.hpp"
#include "AForm.hpp"

//____________________CONSTRUCTORS____________________

Bureaucrat::Bureaucrat() :
_name("dftBureaucrat"),
_grade(LOWEST_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) :
_name(name),
_grade(grade)
{
	CheckGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) :
_name(cpy._name),
_grade(cpy._grade)
{
	CheckGrade();
}

//____________________DESTRUCTORS____________________

Bureaucrat::~Bureaucrat()
{
}

//____________________OVERLOADS____________________

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
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
	if (_grade - 1 < HIGHEST_GRADE)
		throw(GradeTooHighException());
	_grade--;
}

void	Bureaucrat::DecrementGrade()
{
	if (_grade + 1 > LOWEST_GRADE)
		throw (GradeTooLowException());
	_grade++;
}

void	Bureaucrat::CheckGrade()
{
	if (_grade > LOWEST_GRADE)
		throw (GradeTooLowException());
	else if (_grade < HIGHEST_GRADE)
		throw (GradeTooHighException());
}

void	Bureaucrat::SignForm(AForm &form)
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

void	Bureaucrat::ExecuteForm(AForm const &form) const
{
	try
	{
		form.Execute(*this);
		std::cout << _name << " executed " << form.GetName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << *this << " couldn't execute " << form << ". Reason: " << e.what() << std::endl;
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

