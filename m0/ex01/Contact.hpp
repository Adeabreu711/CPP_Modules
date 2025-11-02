#ifndef CONTACT
# define CONTACT

#include <iostream>
#include <string>

class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		std::string	getInfoByID(int info_id);
		void		displayContact(void);
		int			addUser(void);
};

#endif
