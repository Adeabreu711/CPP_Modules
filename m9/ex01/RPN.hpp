#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

#define ERR_INVALID_TOKEN "Error: invalid token"
#define ERR_INVALID_EXP "Error: invalid expression"
#define ERR_INVALID_OP "Error: invalid operation"
#define ERR_ARG "Error: RPN need one string argument"
#define ERR_ILLEGAL_DIV "Error: illegal division"

enum tokenType
{
	OPERATOR,
	DIGIT,
	INVALID
};

struct operator_t
{
	char	op;
	int		(*func)(int, int);
};

int	operate(std::string str);

#endif
