#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	public :
		AForm();
		AForm(const AForm& cpy);
		AForm(const std::string name, const size_t signGrade, const size_t executeGrade);
		~AForm();

		const std::string	GetName() const;
		size_t				GetSignGrade() const;
		size_t				GetExecuteGrade() const;
		bool				GetSigned() const;

		void				BeSigned(Bureaucrat &bureaucrat);
		void				Execute(Bureaucrat const &executor) const;

		AForm&				operator=(const AForm &cpy);

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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	protected:
		virtual void	ExecuteAction(Bureaucrat const&executor) const = 0;

	private :
		const std::string	_name;
		const size_t		_signGrade;
		const size_t		_executeGrade;
		bool				_signed;

		void				CheckGrade() const;
};

std::ostream &operator<<(std::ostream &os, const AForm &cpy);

#endif
