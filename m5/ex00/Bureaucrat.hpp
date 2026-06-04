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
		
		const std::string	GetName() const;
		size_t				GetGrade() const;

		void	IncrementGrade();
		void	DecrementGrade();
		void	CheckGrade();

		Bureaucrat&	operator=(const Bureaucrat &cpy);

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
		size_t				_grade;
};


#endif
