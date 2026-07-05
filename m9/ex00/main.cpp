#include "BitcoinExchange.hpp"

int errorMsg(std::string msg)
{
	std::cerr << msg << std::endl;
	return (1);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (errorMsg(ERR_INVALID_FILE));

	Database		source;
	std::ifstream	input(argv[1]);
	if (!input.is_open())
		return (errorMsg(ERR_INVALID_FILE));

	try 
	{
		parseDb("data.csv", source, ',');
		annoucePrice(source, input);
	}
	catch (std::exception &e)
	{
		std::cerr  << e.what() << std::endl;
		return (1);
	}
	return (0);
}
