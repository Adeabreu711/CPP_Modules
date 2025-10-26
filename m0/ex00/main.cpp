#include <iostream>
#include <string>

#define NO_ARG_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	std::string	upp_str;

	if (argc < 2)
	{
		std::cout << NO_ARG_MSG << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		upp_str = std::string(argv[i]);
		for (size_t i = 0; i < upp_str.length(); i++)
		{
			upp_str[i] = std::toupper(upp_str[i]);
		}
		std::cout << upp_str;
	}
	std::cout << std::endl;
	return (0);
}
