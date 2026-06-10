#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

//___________________CONSTRUCTORS___________________

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("ShrubberyCreationForm", 145, 137),
_target("dft")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm(target, 145, 137),
_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) :
AForm(cpy),
_target(cpy._target)
{
}

//___________________DESTRUCTORS___________________

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

//____________________OVERLOADS____________________

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	if (this == &cpy)
		return (*this);
	AForm::operator=(cpy);
	return (*this);
}

//_____________________GET/SET_____________________

std::string	ShrubberyCreationForm::GetTarget(void) const
{
	return (this->_target);
}

//____________________FUNCTIONS____________________

void ShrubberyCreationForm::ExecuteAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::ofstream file (GetTarget().append("_shrubbery").c_str());

	for (size_t i = 0; i < 2; i++)
	{
		file <<
		"        # #### ####" << std::endl <<
		"      ### \\/#|### |/####" << std::endl <<
		"     ##\\/#/ \\||/##/_/##/_#" << std::endl <<
		"   ###  \\/###|/ \\/ # ###" << std::endl <<
		" ##_\\_#\\_\\## | #/###_/_####" << std::endl <<
		"## #### # \\ #| /  #### ##/##" << std::endl <<
		" __#_--###`  |{,###---###-~" << std::endl <<
		"           \\ }{" << std::endl <<
		"            }}{" << std::endl <<
		"            }}{" << std::endl <<
		"       ejm  {{}" << std::endl <<
		"      , -=-~{ .-^- _" << std::endl <<
		"            `}" << std::endl <<
		"             {" << std::endl;
	}
		file.close();
}
