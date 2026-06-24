#include "Span.hpp"
#include <climits>

//___________________CONSTRUCTORS___________________

Span::Span(void) :
_size(0),
_content()
{
}

Span::Span(unsigned int size) :
_size(size),
_content()
{
}

Span::Span(const Span &cpy)
{
	*this = cpy;
}

//___________________DESTRUCTORS___________________

Span::~Span(void)
{
}

//____________________OVERLOADS____________________

Span& Span::operator=(const Span &cpy)
{
	_content =	cpy._content;
	_size =		cpy._size;
	return (*this);
}

//_____________________GET/SET_____________________

unsigned int	Span::size(void) const
{
	return (_size);
}

std::vector<int>	Span::content(void) const
{
	return (_content);
}

//____________________FUNCTIONS____________________

void	Span::addNumber(int nb)
{
	if (_content.size() >= _size)
		throw (std::range_error("Span is full"));
	_content.push_back(nb);
}

int	Span::shortestSpan() const
{
	if (_content.size() < 2)
		throw (std::range_error("Span need more than one number"));
	std::vector<int> tmp = _content;
	std::sort(tmp.begin(), tmp.end());
	int	shortest = INT_MAX;
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
	}
	return (shortest);
}

int	Span::longestSpan() const
{
	if (_content.size() < 2)
		throw (std::range_error("Span need more than one number"));
	std::vector<int> tmp = _content;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}
