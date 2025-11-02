#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public :
		PhoneBook();
		void	searchUser(void);
		void	addUser(void);
	private :
		Contact	contact[8];
		int		contact_size;
		void	displayPhoneBook(void);
};

#endif
