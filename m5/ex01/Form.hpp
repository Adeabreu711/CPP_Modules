#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	public :
		Form();
		Form(const Form& cpy);
		Form(const std::string name, const size_t signGrade, const size_t executeGrade);
		~Form();

		const std::string	GetName() const;
		size_t				GetSignGrade() const;
		size_t				GetExecuteGrade() const;
		bool				GetSigned() const;

		void				CheckGrade() const;
		void				BeSigned(Bureaucrat &bureaucrat);

		Form&				operator=(const Form &cpy);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private :
		const std::string	_name;
		const size_t		_signGrade;
		const size_t		_executeGrade;
		bool				_signed;
};

std::ostream &operator<<(std::ostream &os, const Form &cpy);

#endif
