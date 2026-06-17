#include "Array.hpp"

int main()
{
	Array<int> empty;
	std::cout << "[empty] Size: " << empty.size() << std::endl << std::endl;

	Array<int> iArray(10);
	std::cout << "[iArray] Size: "<< iArray.size() << std::endl;
	for (size_t i = 0; i < iArray.size(); i++)
	{
		iArray[i] = i + 1;
		std::cout << "[iArray][" << i << "]= "<< iArray[i] << std::endl;
	}
	std::cout << std::endl;
	Array<std::string> sArray(2);
	std::cout << "[sArray] Size: "<< iArray.size() << std::endl;
	sArray[0] = "Salut";
	sArray[1] = "Hello";
	for (size_t i = 0; i < sArray.size(); i++)
	{
		std::cout << "[iArray][" << i << "]= "<< sArray[i] << std::endl;
	}
	Array<std::string> cpy(sArray);
	std::cout << "[cpy] Size: "<< iArray.size() << std::endl;
	for (size_t i = 0; i < sArray.size(); i++)
	{
		std::cout << "[cpy][" << i << "]= "<< cpy[i] << std::endl;
	}
	return (0);
}
