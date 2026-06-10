#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef AForm* (*FormMaker)(std::string target);

struct FormMap
{
	std::string name;
	FormMaker fm;
};

//___________________CONSTRUCTORS___________________

Intern::Intern(void)
{
}

Intern::Intern(const Intern &cpy)
{
	*this = cpy;
}

//___________________DESTRUCTORS___________________

Intern::~Intern(void)
{
}

//____________________OVERLOADS____________________

Intern& Intern::operator=(const Intern &cpy)
{
	(void)cpy;
	return (*this);
}

//____________________FUNCTIONS____________________

static AForm* MakePresidentialPardonFrom(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm* MakeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* MakeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::MakeForm(std::string name, std::string target)
{
	FormMap forms[] =
	{
		{"PresidentialPardonForm", MakePresidentialPardonFrom},
		{"RobotomyRequestForm", MakeRobotomyRequestForm},
		{"ShrubberyCreationForm", MakeShrubberyCreationForm},
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i].name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (forms[i].fm(target));
		}
	}
	std::cout << "\"" << name << "\"" <<" form doesn't exist "<< std::endl;
	return (NULL);
}
