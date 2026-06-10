#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\nCONSTRUCTOS\n" << std::endl;
	Bureaucrat low("Bob", 150);
	Bureaucrat medium("Vlad", 75);
	Bureaucrat high("Djimi", 1);

	std::cout << "\nHIGH TEST\n" << std::endl;
	try
	{
		high.IncrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << ". Info : " << high << std::endl;
	}

	std::cout << "\nMEDIUM TEST\n" << std::endl;
	try
	{
		medium.IncrementGrade();
		medium.DecrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "Info : " << medium << std::endl;
	}

	std::cout << "\nLOW TEST\n" << std::endl;
	try
	{
		low.DecrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "Info : " << low << std::endl;
	}
	std::cout << "\nDESTRUCTORS\n" << std::endl;
	return (0);
}
