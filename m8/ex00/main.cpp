#include "easyfind.hpp"
#include <vector>
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
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	std::list<int> lst2;

try
{
	printContainer(vec, "vector");
	std::vector<int>::const_iterator itVec = easyfind(vec, 20);
	std::cout << "To find : " << *itVec << std::endl << std ::endl;

	printContainer(lst, "list");
	std::list<int>::const_iterator itList = easyfind(lst, 2);
	std::cout << "To find : " << *itList << std::endl << std ::endl;

	easyfind(vec, 999);
}
catch (const std::exception &e)
{
	std::cout << "Exception : " << e.what() << std::endl;
}
	return (0);
}
