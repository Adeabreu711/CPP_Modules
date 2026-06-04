#include "Form.hpp"

//____________________CONSTRUCTORS____________________

Form::Form() : 
_name("dftForm"),
_signGrade(1),
_executeGrade(1),
_signed(false)
{
	std::cout << "Default Constructor called [" << _name << "]" << std::endl;
}

Form::Form(const std::string name, const size_t signGrade, const size_t executeGrade) : 
_name(name), 
_signGrade(signGrade),
_executeGrade(executeGrade),
_signed(false)
{
	std::cout << "Custom Constructor called [" << _name << "]" << std::endl;
}

//____________________DESTRUCTORS____________________

Form::~Form()
{
	std::cout << "Default Destructor called [" << _name << "]" << std::endl;
}

//____________________OVERLOADS____________________

std::ostream &operator<<(std::ostream &os, const Form &cpy)
{
	os << cpy.GetName() << ", sign grade " << cpy.GetSignGrade() 
	<< ", execute grade" << cpy.GetExecuteGrade() << ", signed [" 
	<< cpy.GetSigned() << "]";
	return (os);
}

//____________________FUNCTIONS____________________

void	Form::CheckGrade(Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() > _signGrade)
		throw (GradeTooLowException());
	else if (bureaucrat.GetGrade() <  HIGHEST_GRADE)
		throw (GradeTooHighException());
}

void	Form::BeSigned(Bureaucrat &bureaucrat)
{
	_signed = true;
	//TODO
}

//____________________GET/SET____________________

const std::string	Form::GetName() const
{
	return(_name);
}

const size_t	Form::GetSignGrade() const
{
	return(_signGrade);
}

const size_t	Form::GetExecuteGrade() const
{
	return(_executeGrade);
}

bool	Form::GetSigned() const
{
	return(_signed);
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


