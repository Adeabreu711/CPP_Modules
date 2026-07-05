#include "PmergeMe.hpp"
#include <vector>
#include <climits>
#include <cerrno>
#include <stdlib.h>

int	errorMsg(std::string msg)
{
	std::cerr << msg << std::endl;
	return (1);
}

template <typename T>
T parseArgs(int argc, char **argv)
{
	T	container;

	for (int i = 1; i < argc; i++)
	{
		char *endptr;
		errno = 0;
		long value = std::strtol(argv[i], &endptr, 10);

		if (endptr == argv[i] || *endptr != '\0' 
				|| errno == ERANGE || value < 0 || value > INT_MAX)
			throw std::invalid_argument("Error : invalid token => " + static_cast<std::string>(argv[i]));

		container.push_back(static_cast<int>(value));
	}
	return (container);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (errorMsg("Error: Too few arguments"));
	try
	{
		std::vector<int> vec = parseArgs< std::vector<int> >(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
