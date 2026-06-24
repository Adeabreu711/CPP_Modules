#include "MutantStack.hpp"

//___________________CONSTRUCTORS___________________

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &cpy)
{
	*this = cpy;
}

//___________________DESTRUCTORS___________________

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

//____________________OVERLOADS____________________

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &cpy)
{
	if (this == &cpy)
		return (*this);
	std::stack<T>::operator=(cpy);
	return (*this);
}

//____________________ITERATORS____________________

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

//__________________CONST_ITERATORS__________________

template <typename T>
typename MutantStack<T>::c_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::c_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}
