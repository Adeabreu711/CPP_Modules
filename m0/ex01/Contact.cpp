#include "Contact.hpp"

void	Contact::addUser()
{
	std::cout << "first_name     : ";
	std::getline(std::cin, first_name);
	std::cout << "last_name      : ";
	std::getline(std::cin, last_name);
	std::cout << "nickname       : ";
	std::getline(std::cin, nickname);
	std::cout << "phone_number   : ";
	std::getline(std::cin, phone_number);
	std::cout << "darkest_secret : ";
	std::getline(std::cin, darkest_secret);
	std::cout	
		<< first_name << " "
		<< last_name << " "
		<< "added !" << std::endl;
}
