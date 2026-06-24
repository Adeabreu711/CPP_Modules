#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
	public :
	Span(const Span &cpy);
	Span(unsigned int size);
	~Span(void);

	Span &operator=(const Span &fixed);

	unsigned int		size(void) const;
	std::vector<int>	content(void) const;

	void			addNumber(int nb);
	int				shortestSpan() const;
	int				longestSpan() const;

	template <typename T>
	void	addRange(T begin, T end);

	private :
		Span(void);

		unsigned int		_size;
		std::vector<int>	_content;
};

template <typename T>
void	Span::addRange(T begin, T end)
{
	if(_content.size() + std::distance(begin, end) > _size)
		throw (std::overflow_error("Span need more size"));
	for (T it = begin; it != end; it++)
	{
		_content.push_back(*it);
	}
}

#endif
