#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	bob("Bob", 10);
	Bureaucrat	greg("Greg", 16);

	Form		exam("Exam", 15, 15);
	Form		carTuning("Car Tuning", 40, 40);

	greg.SignForm(exam);
	greg.SignForm(carTuning);
	bob.SignForm(exam);

	try
	{
		Form highTest("High Test", 0, 150); //Grade too high
		Form lowTest("Low Test", 1, 151); //Low too high
	}
	catch(std::exception &e)
	{
		std::cout << "Exeption: " << e.what() << std::endl;
	}
	return (0);
}
