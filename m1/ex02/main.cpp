#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "string    <memory adress>: " << &string << std::endl;
	std::cout << "stringPTR <memory adress>: " << &stringPTR << std::endl;
	std::cout << "stringREF <memory adress>: " << &stringREF << std::endl << std::endl;

	std::cout << "string    <value>: " << string << std::endl;
	std::cout << "stringPTR <value>: " << *stringPTR << std::endl;
	std::cout << "stringREF <value>: " << stringREF << std::endl;
	return (0);
}
