#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	try
	{
		Bureaucrat hacker("Hacker Lvl 200", 1);
		Bureaucrat noob("Noob Lvl 1", 150);

		ShrubberyCreationForm	shrub("garden");
		RobotomyRequestForm		robot("Nick");
		PresidentialPardonForm	pardon("Big T");

		std::cout << "\nFORMS\n" << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		std::cout << "\nEXECUTE UNSIGNED FORM\n" << std::endl;
		try
		{
			shrub.Execute(hacker);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "\nTRY TO SIGN\n" << std::endl;
		noob.SignForm(shrub);

		std::cout << "\nSIGN FORMS\n" << std::endl;
		hacker.SignForm(shrub);
		hacker.SignForm(robot);
		hacker.SignForm(pardon);

		std::cout << "\nEXECUTION\n" << std::endl;
		hacker.ExecuteForm(shrub);
		hacker.ExecuteForm(robot);
		hacker.ExecuteForm(pardon);

		std::cout << "\nTRY TO EXECUTE" << std::endl;
		noob.ExecuteForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
