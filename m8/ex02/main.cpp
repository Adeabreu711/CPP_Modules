#include "MutantStack.hpp"

int main()
{
	MutantStack<int> ms;

	ms.push(10);
	ms.push(20);
	ms.push(30);

	std::cout << "Top: " << ms.top() << std::endl;

	std::cout << "\nIteration:" << std::endl;
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\nConst iteration:" << std::endl;
	const MutantStack<int> c_ms = ms;

	for (MutantStack<int>::c_iterator it = c_ms.begin(); it != c_ms.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "\nCopy test:" << std::endl;
	MutantStack<int> copy = ms;
	copy.push(99);

	std::cout << "Original top: " << ms.top() << std::endl;
	std::cout << "Copy top: " << copy.top() << std::endl;

	return (0);
}

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

