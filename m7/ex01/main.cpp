#include "iter.hpp"

template <typename T>
void	print(T var)
{
	std::cout << var << std::endl;
}
int main()
{
	int			iArray[5] = {0, 1, 2, 3, 4};
	char		cArray[3] = {'a', 'b', 'c'};
	std::string	sArray[2] = {"Bonjour!", "Au revoir!"};

	iter(iArray, 5, print<int>);
	iter(cArray, 3, print<char>);
	iter(sArray, 2, print<std::string>);

	return (0);
}
