#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

class Bureaucrat
{
	public :
		Bureaucrat();
		Bureaucrat(const Bureaucrat& cpy);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
	private :
		const std::string _name;
		size_t	_grade;

	Bureaucrat&	operator=(const Bureaucrat &cpy);

	const std::string	GetName() const;
	size_t	GetGrade() const;

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
};


#endif
