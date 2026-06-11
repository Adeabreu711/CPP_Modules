#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: need one argument" << std::endl;
		return (1);
	}
	ScalarConverter::Convert(argv[1]);
	return (0);
}
