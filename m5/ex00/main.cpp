#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat *test = new Bureaucrat("Bob", 5);

		try 
		{
			test->IncrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "\033[33mIncrementing grade of " << test->GetName() <<
			" failed: " << e.what() << "\033[0m" << std::endl;
		}
	return (0);
}
