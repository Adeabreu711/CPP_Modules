#include "PhoneBook.hpp"
#include <cstdlib>
#include <cctype>

#define MAX_CONTACT 8
#define CELL_SIZE 10
#define DASH_LINE "-------------------------------------------"

//PhoneBook constructor
PhoneBook::PhoneBook() :
	contact(),
	contact_size(0)
{}

//[ADD_FUNCTION]______________________________________

void	PhoneBook::addUser(void)
{
	if (contact_size >= MAX_CONTACT)
	{
		std::cout << "MAX CONTACT" << std::endl;
		for (int i = 1; i < MAX_CONTACT; i++)
			contact[i- 1] = contact[i];
		if (contact[MAX_CONTACT - 1].addUser() == -1)
			std::cout
		return ;
	}
	contact[contact_size++].addUser();
	std::cout << DASH_LINE << std::endl;

}

//[SEARCH_UTILS]______________________________________

void	printFormatedString(std::string str)
{
	int	missing_chars;

	missing_chars = CELL_SIZE - str.size();
	if (missing_chars >= 0)
		str.insert(0, missing_chars ,' ');
	else
	{
		str.erase(CELL_SIZE);
		str.push_back('.');
	}
	std::cout << str << "|";
}

int	getUserSearchInput(int contact_size)
{
	std::string	input;
	int			contact_id;

	std::cin >> input;
	if (!std::isdigit(input[0]))
	{
		std::cout << "Error: \""  << input << "\":"
			<< " is not a valid input" << DASH_LINE << std::endl;
		return (-1);
	}
	contact_id = std::atoi(input.c_str());
	if (contact_id < 0 || contact_id > contact_size)
	{
		std::cout << "Error: \""  << input << "\":"
			<< " is out of range" << DASH_LINE << std::endl;
		return (-1);
	}
	return (contact_id);
}

void	PhoneBook::displayPhoneBook(void)
{
	for (int line = 0; line < contact_size; line++)
	{
		std::cout << "|";
		for (int col = 0; col < 4; col++)
		{
			printFormatedString(contact[line].getInfoByID(col));
		}
		std::cout << std::endl;
	}
}

//[SEARCH_FUNCTION]______________________________________


void	PhoneBook::searchUser(void)
{
	int			contact_id;

	std::cout << std::endl;
	if (contact_size <= 0)
	{
		std::cout << "Seems like you don't have any contacts"
		<< DASH_LINE << std::endl;
		return ;
	}
	displayPhoneBook();
	std::cout << std::endl << "Enter the contact ID you want to search: ";
	contact_id = getUserSearchInput(contact_size);
	if (contact_id != -1)
		contact[contact_id].displayContact();
	std::cout << DASH_LINE << std::endl;
}
