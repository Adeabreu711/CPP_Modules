#include "Contact.hpp"

std::string	Contact::getInfoByID(int info_id)
{
	if (info_id == 0)
		return (first_name);
	if (info_id == 1)
		return (last_name);
	if (info_id == 2)
		return (nickname);
	if (info_id == 3)
		return (phone_number);
	if (info_id == 4)
		return (darkest_secret);
	return ("");
}

void	Contact::displayContact(void)
{
	std::cout
		<<	first_name << std::endl
		<<	last_name << std::endl
		<<	nickname << std::endl
		<<	phone_number << std::endl
		<<	darkest_secret << std::endl;
}

int	Contact::addUser(void)
{
	std::cout << "first_name     : ";
	if (!std::getline(std::cin, first_name) || first_name.empty())
		return (0);
	std::cout << "last_name      : ";
	if (!std::getline(std::cin, last_name) || last_name.empty())
		return (0);
	std::cout << "nickname       : ";
	if (!std::getline(std::cin, nickname) || nickname.empty())
		return (0);
	std::cout << "phone_number   : ";
	if (!std::getline(std::cin, phone_number) || phone_number.empty())
		return (0);
	std::cout << "darkest_secret : ";
	if (!std::getline(std::cin, darkest_secret) || darkest_secret.empty())
		return (0);
	std::cout
		<< std::endl
		<< first_name << " "
		<< last_name << " "
		<< "added !" << std::endl;
	return (1);
}
