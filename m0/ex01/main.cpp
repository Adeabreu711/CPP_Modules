#include "PhoneBook.hpp"

int	main(void)
{
	int			id = 0;
	PhoneBook	phone_book;
	std::string	input;

	while (1)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phone_book.addUser();
			id++;
		}
		if (input == "SEARCH")
			phone_book.searchUser();
	}
	return (0);
}
