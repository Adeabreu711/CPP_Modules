#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat *test = new Bureaucrat("Bob", 1);

	try 
	{
		test->IncrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *test << std::endl;
	return (0);
}
