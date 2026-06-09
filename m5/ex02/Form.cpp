#include "Form.hpp"
#include "Bureaucrat.hpp"

//____________________CONSTRUCTORS____________________

Form::Form() :
_name("dftForm"),
_signGrade(LOWEST_GRADE),
_executeGrade(LOWEST_GRADE),
_signed(false)
{
	//std::cout << "Default Form Constructor called [" << _name << "]" << std::endl;
}

Form::Form(const std::string name, const size_t signGrade, const size_t executeGrade) :
_name(name),
_signGrade(signGrade),
_executeGrade(executeGrade),
_signed(false)
{
	//std::cout << "Custom Form Constructor called [" << _name << "]" << std::endl;
	CheckGrade();
}

Form::Form(const Form& cpy) :
_name(cpy._name),
_signGrade(cpy._signGrade),
_executeGrade(cpy._executeGrade),
_signed(cpy._signed)
{
	//std::cout << "Copy Form Constructor called [" << _name << "]" << std::endl;
	CheckGrade();
}

//____________________DESTRUCTORS____________________

Form::~Form()
{
	//std::cout << "Default Form Destructor called [" << _name << "]" << std::endl;
}

//____________________OVERLOADS____________________

std::ostream &operator<<(std::ostream &os, const Form &cpy)
{
	os << cpy.GetName() << ", sign grade " << cpy.GetSignGrade()
	<< ", execute grade " << cpy.GetExecuteGrade() << ", [signed "
	<< cpy.GetSigned() << "]";
	return (os);
}

//____________________FUNCTIONS____________________

void	Form::CheckGrade() const
{
	if (_signGrade > LOWEST_GRADE || _executeGrade > LOWEST_GRADE)
		throw (GradeTooLowException());
	else if (_signGrade < HIGHEST_GRADE || _executeGrade < HIGHEST_GRADE)
		throw (GradeTooHighException());
}

void	Form::BeSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() > _signGrade)
		throw(GradeTooLowException());
	_signed = true;
}

//____________________GET/SET____________________

const std::string	Form::GetName() const
{
	return(_name);
}

size_t	Form::GetSignGrade() const
{
	return(_signGrade);
}

size_t	Form::GetExecuteGrade() const
{
	return(_executeGrade);
}

bool	Form::GetSigned() const
{
	return(_signed);
}

//____________________EXEPTIONS____________________

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};


