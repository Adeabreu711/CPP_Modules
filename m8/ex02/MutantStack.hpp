#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator c_iterator;

		MutantStack();
		MutantStack(const MutantStack &cpy);
		~MutantStack();
		MutantStack &operator=(const MutantStack &cpy);

		iterator begin();
		iterator end();

		c_iterator begin() const;
		c_iterator end() const;

};

#include "MutantStack.tpp"

#endif
