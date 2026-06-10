#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

//___________________CONSTRUCTORS___________________

RobotomyRequestForm::RobotomyRequestForm(void) :
AForm("RobotomyRequestForm", 72, 45),
_target("dft")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm(target, 72, 45),
_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) :
AForm(cpy),
_target(cpy._target)
{
}

//___________________DESTRUCTORS___________________

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

//____________________OVERLOADS____________________

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	if (this == &cpy)
		return (*this);
	AForm::operator=(cpy);
	return (*this);
}

//_____________________GET/SET_____________________

std::string	RobotomyRequestForm::GetTarget(void) const
{
	return (this->_target);
}

//____________________FUNCTIONS____________________

void RobotomyRequestForm::ExecuteAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << "~~ddrrr~r drilling noises d~~ddrrr~, ";

	if (rand() % 2)
		std::cout << _target << " has been Robotomized" << std::endl;
	else
		std::cout << _target << " is agonizing because Robotomization failed" << std::endl;
}
