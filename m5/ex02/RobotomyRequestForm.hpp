#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &fixed);

		std::string	GetTarget(void) const;


	protected :
		void		ExecuteAction(Bureaucrat const &executor) const;

	private :
		const std::string	_target;
};

#endif
