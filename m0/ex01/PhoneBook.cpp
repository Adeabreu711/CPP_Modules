#include "PhoneBook.hpp"

PhoneBook::PhoneBook() :
	contact(),
	contact_size(0)
{}


void	PhoneBook::addUser(void)
{
	contact[contact_size++].addUser();
}

void	formatString()
{
	
}

void	PhoneBook::printLine(void)
{
	 
}

void	PhoneBook::searchUser(void)
{
	std::cout << contact_size << "\n";
	if (contact_size < 0)
		return ;
	for (int line = 0; line < contact_size; line++)
	{
		std::cout << std::endl;
	}
}
