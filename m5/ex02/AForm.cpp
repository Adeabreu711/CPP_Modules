#include "AForm.hpp"
#include "Bureaucrat.hpp"

//____________________CONSTRUCTORS____________________

AForm::AForm() :
_name("dftForm"),
_signGrade(LOWEST_GRADE),
_executeGrade(LOWEST_GRADE),
_signed(false)
{
}

AForm::AForm(const std::string name, const size_t signGrade, const size_t executeGrade) :
_name(name),
_signGrade(signGrade),
_executeGrade(executeGrade),
_signed(false)
{
	CheckGrade();
}

AForm::AForm(const AForm& cpy) :
_name(cpy._name),
_signGrade(cpy._signGrade),
_executeGrade(cpy._executeGrade),
_signed(cpy._signed)
{
	CheckGrade();
}

//____________________DESTRUCTORS____________________

AForm::~AForm()
{
}

//____________________OVERLOADS____________________

AForm	&AForm::operator=(const AForm &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &cpy)
{
	os << cpy.GetName() << ", sign grade " << cpy.GetSignGrade()
	<< ", execute grade " << cpy.GetExecuteGrade() << ", [signed "
	<< cpy.GetSigned() << "]";
	return (os);
}

//____________________FUNCTIONS____________________

void	AForm::CheckGrade() const
{
	if (_signGrade > LOWEST_GRADE || _executeGrade > LOWEST_GRADE)
		throw (GradeTooLowException());
	else if (_signGrade < HIGHEST_GRADE || _executeGrade < HIGHEST_GRADE)
		throw (GradeTooHighException());
}

void	AForm::BeSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() > _signGrade)
		throw(GradeTooLowException());
	_signed = true;
}

void	AForm::Execute(Bureaucrat const &executor) const
{
	if (!GetSigned())
		throw (AForm::NotSignedException());
	if (executor.GetGrade() > GetExecuteGrade())
		throw (AForm::GradeTooLowException());

	ExecuteAction(executor);
}

//____________________GET/SET____________________

const std::string	AForm::GetName() const
{
	return(_name);
}

size_t	AForm::GetSignGrade() const
{
	return(_signGrade);
}

size_t	AForm::GetExecuteGrade() const
{
	return(_executeGrade);
}

bool	AForm::GetSigned() const
{
	return(_signed);
}

//____________________EXEPTIONS____________________

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Not signed");
};


