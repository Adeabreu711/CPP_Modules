#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	while (1)
	{
		if (!std::getline(std::cin, input))
			break ;
		if (input == "ADD")
			phone_book.addUser();
		if (input == "SEARCH")
			phone_book.searchUser();
		if (input == "EXIT")
			return (0);
	}
	return (1);
}
