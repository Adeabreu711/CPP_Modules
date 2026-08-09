#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cstdlib>

int	_add(int a, int b){return (a + b);}
int	_sub(int a, int b){return (a - b);}
int	_mult(int a, int b){return (a * b);}
int	_div(int a, int b){return (a / b);}

static tokenType	getTokenType(std::string token)
{
	if (token == "+" || token == "-" || token == "/" || token == "*")
		return (OPERATOR);
	if (token.size() == 1 && std::isdigit(token[0]))
		return (DIGIT);
	return (INVALID);
}

static	void applyOperator(std::string op, std::stack<int> &stack)
{
	if (stack.size() < 2)
		return ;
	operator_t opDic[] = {{'+', _add}, {'-', _sub}, {'*', _mult}, {'/', _div}};
	int	a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();

	for (size_t i = 0; i < 4; i++)
	{
		if (op[0] == opDic[i].op)
		{
			if (op[0] == '/' && a == 0)
				throw (std::runtime_error(ERR_ILLEGAL_DIV));
			stack.push(opDic[i].func(b, a));
			return ;
		}
	}
}

int	operate(std::string str)
{
	std::stack<int> stack;

	std::stringstream ss(str);
	std::string token;

	while (ss >> token)
	{
		tokenType type = getTokenType(token);
		if (type == INVALID)
			throw (std::runtime_error(ERR_INVALID_TOKEN));
		if (type == DIGIT)
			stack.push(std::atoi(token.c_str()));
		else if (type == OPERATOR)
			applyOperator(token, stack);
	}
	if (stack.size() != 1)
		throw (std::runtime_error(ERR_INVALID_EXP));
	return (stack.top());
}

