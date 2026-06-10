#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	bob("Bob", 10);
	Bureaucrat	greg("Greg", 16);

	Form		exam("Exam", 15, 15);
	Form		carTuning("Car Tuning", 40, 40);

	std::cout << bob << std::endl;
	std::cout << greg << std::endl;
	std::cout << exam << std::endl;
	std::cout << carTuning << std::endl;

	std::cout << "\nSIGN TEST\n" << std::endl;
	greg.SignForm(exam); //KO
	greg.SignForm(carTuning); //OK
	bob.SignForm(exam); //OK

	std::cout << "\nAFTER SIGN\n" << std::endl;
	std::cout << exam << std::endl;
	std::cout << carTuning << std::endl;

	std::cout << "\nEXCEPTION TEST\n" << std::endl;
	try
	{
		Form highTest("High Test", 0, 150);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Form lowTest("Low Test", 1, 151);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
