#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat *low = new Bureaucrat("Bob", 150);
	Bureaucrat *medium = new Bureaucrat("Vlad", 75);
	Bureaucrat *high = new Bureaucrat("Djimi", 1);

	//HIGH_TEST
	try 
	{
		high->IncrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << ". Info : " << *high << std::endl;
	}

	//MEDIUM_TEST
	try 
	{
		medium->IncrementGrade();
		medium->DecrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "Info : " << *medium << std::endl;
	}

	//LOW_TEST
	try 
	{
		low->DecrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "Info : " << *low << std::endl;
	}
	return (0);
}
