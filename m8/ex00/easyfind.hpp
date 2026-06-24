#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(T &container, int nb)
{
	typename T::const_iterator	output;

	output = std::find(container.begin(), container.end(), nb);
	if (output == container.end())
		throw (std::runtime_error("Value not found"));
	return (output);
}

#endif
