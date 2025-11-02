#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	while (1)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
			phone_book.addUser();
		if (input == "SEARCH")
			phone_book.searchUser();
		if (input == "EXIT")
			return (0);
	}
	return (0);
}
