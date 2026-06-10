#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &fixed);

		std::string	GetTarget(void) const;


	protected :
		void		ExecuteAction(Bureaucrat const &executor) const;

	private :
		const std::string	_target;
};

#endif
