#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//___________________CONSTRUCTORS___________________

PresidentialPardonForm::PresidentialPardonForm(void) :
AForm("PresidentialPardonForm", 25, 5),
_target("dft")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm(target, 25, 5),
_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) :
AForm(cpy),
_target(cpy._target)
{
}

//___________________DESTRUCTORS___________________

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

//____________________OVERLOADS____________________

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	if (this == &cpy)
		return (*this);
	AForm::operator=(cpy);
	return (*this);
}

//_____________________GET/SET_____________________

std::string	PresidentialPardonForm::GetTarget(void) const
{
	return (this->_target);
}

//____________________FUNCTIONS____________________

void PresidentialPardonForm::ExecuteAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
