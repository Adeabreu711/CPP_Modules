#include "RPN.hpp"

int errorMsg(std::string msg)
{
	std::cerr << msg << std::endl;
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (errorMsg(ERR_ARG));
	try
	{
		int result = operate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
