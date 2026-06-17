#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T> class Array
{
	public :
		Array(void);
		Array(const Array &other);
		Array(unsigned int n);
		~Array(void);

		Array			&operator=(const Array &fixed);
		T&				operator[](unsigned int index);

		unsigned int	size() const;

	private :
		T*				_data;
		unsigned int	_size;
};

#include "Array.tpp"

#endif
