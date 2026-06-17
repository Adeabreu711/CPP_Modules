#include "Array.hpp"

//___________________CONSTRUCTORS___________________

template <typename T>
Array<T>::Array() :
_data(NULL),
_size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) :
_data(new T[n]),
_size(n)
{
}

template <typename T>
Array<T>::Array(const Array &other) :
_data(new T[other._size]),
_size(other._size)
{
	*this = other;
}

//___________________DESTRUCTORS___________________

template <typename T>
Array<T>::~Array(void)
{
	delete[] (_data);
}

//____________________OVERLOADS____________________

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);
	_size = other._size;
	if (other._size <= 0)
	{
		_data = NULL;
		return (*this);
	}
	_data = new T[other._size];
	for (size_t i = 0; i < other._size; i++)
		_data[i] = other._data[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw (std::out_of_range("Index out of bounds"));

	return (_data[index]);
}

//_____________________GET/SET_____________________

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
