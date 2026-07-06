#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <stdlib.h>
#include <climits>
#include <cerrno>
#include <ctime>

#include <vector>
#include <list>

typedef std::vector<int>	Ivec;
typedef std::list<int>		Ilist;


void	fordJohnson(Ivec &input);
void	fordJohnson(Ilist &input);

//___________________TEMPLATES___________________

template <typename T>
void	checkDuplicates(const T &container)
{
	typename	T::const_iterator it;
	typename	T::const_iterator jt;

	for (it = container.begin(); it != container.end(); ++it)
	{
		jt = it;
		++jt;

		for (; jt != container.end(); ++jt)
		{
			if (*it == *jt)
				throw (std::invalid_argument("Error: duplicate value found"));
		}
	}
}

template <typename T>
T	parseArgs(int argc, char **argv)
{
	T	container;

	for (int i = 1; i < argc; i++)
	{
		char *endptr;
		errno = 0;
		long value = std::strtol(argv[i], &endptr, 10);

		if (endptr == argv[i] || *endptr != '\0' 
				|| errno == ERANGE || value < 0 || value > INT_MAX)
			throw std::invalid_argument("Error : invalid token => " + static_cast<std::string>(argv[i]));

		container.push_back(static_cast<int>(value));
	}
	checkDuplicates(container);
	return (container);
}

template <typename T>
void	printContainer(const T &container, std::string str)
{
	typename T::const_iterator it;

	std::cout << str << ": ";

	for (it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}
#endif
