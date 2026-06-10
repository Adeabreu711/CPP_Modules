#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	try
	{
		Intern intern;

		AForm* shrub = intern.MakeForm("ShrubberyCreationForm", "Garden");
		AForm* robot = intern.MakeForm("RobotomyRequestForm", "Nick");
		AForm* pardon = intern.MakeForm("PresidentialPardonForm","Big T");
		AForm* invalid = intern.MakeForm("sdjqkshgzi", "Nobody");

		Bureaucrat hacker("Hacker Lvl 200", 1);
		Bureaucrat noob("Noob Llv 1", 150);

		std::cout << "\nSIGN\n" << std::endl;

		if (shrub)
			hacker.SignForm(*shrub);
		if (robot)
			hacker.SignForm(*robot);
		if (pardon)
			hacker.SignForm(*pardon);

		std::cout << "\nEXECUTE\n" << std::endl;

		if (shrub)
			hacker.ExecuteForm(*shrub);
		if (robot)
			hacker.ExecuteForm(*robot);
		if (pardon)
			hacker.ExecuteForm(*pardon);

		std::cout << "\nLOW GRADE TEST\n" << std::endl;

		if (shrub)
			noob.ExecuteForm(*shrub);

		delete shrub;
		delete robot;
		delete pardon;
		delete invalid;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
