#include "Span.hpp"
#include <list>

template <typename T>
void printContainer(const T &container, std::string name)
{
	typename T::const_iterator it;

	std::cout << name << " : ";

	for (it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}
int main()
{
	try
	{
		std::cout << "BASIC" << std::endl;

		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		printContainer(sp.content(), "span");

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "\nOVERFLOW" << std::endl;

		try
		{
			sp.addNumber(42); // doit throw
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		std::cout << "\nVECTOR RANGE" << std::endl;

		Span sp2(10);
		std::vector<int> v;

		for (int i = 0; i < 5; i++)
			v.push_back(i * 10);

		sp2.addRange(v.begin(), v.end());
		printContainer(sp2.content(), "vector");

		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

		std::cout << "\nLIST" << std::endl;

		Span sp3(10);
		std::list<int> l;

		l.push_back(100);
		l.push_back(50);
		l.push_back(200);

		sp3.addRange(l.begin(), l.end());
		printContainer(l, "list");

		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
