#include "Base.hpp"
#include <ctime>
#include <cstdlib>

Base*	Generate(void)
{
	int	randomNb = rand() % 3;

	if (randomNb == 0)
		return (new A());
	if (randomNb == 1)
		return (new B());
	return (new C());
}

void	Identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void Identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch(...){}
}

int main()
{
	std::srand(std::time(NULL));

	Base* RandomBase1= Generate();
	Base* RandomBase2= Generate();
	Base* RandomBase3= Generate();

	Identify(RandomBase1);
	Identify(*RandomBase1);
	std::cout << std::endl;

	Identify(RandomBase2);
	Identify(*RandomBase2);
	std::cout << std::endl;

	Identify(RandomBase3);
	Identify(*RandomBase3);
	return (0);
}
