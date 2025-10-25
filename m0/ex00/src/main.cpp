#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	(void)argc;
	std::string	upp_str;

	upp_str = std::string(argv[1]);
	for (size_t i = 0; i < upp_str.length(); i++)
	{
		upp_str[i] = std::toupper(upp_str[i]);
	}

	std::cout << upp_str << std::endl;
}
