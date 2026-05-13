#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define MSG_GRADETOOHIGH ""
#define MSG_GRADETOOLOW ""


class Bureaucrat : public std::exception
{
	public :
		Bureaucrat(const std::string name, int grade);
		virtual ~Bureaucrat() throw();
		virtual const char* what() const throw();
	private : 
		const std::string _name;
		int	_grade;
};


#endif
