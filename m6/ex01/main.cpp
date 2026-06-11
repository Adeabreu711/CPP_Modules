#include "Serializer.hpp"

int main()
{
	Data data;

	data.value = 42;
	data.ptr = &data.value;

	Data* dftPtr = &data;

	uintptr_t raw = Serializer::Serialize(dftPtr);
	long test = (long)dftPtr;

	Data* rstPtr = Serializer::Deserialize(raw);
	Data* testPtr = (Data*)test;

	std::cout << "Default pointer: " << dftPtr << std::endl;
	std::cout << "Restored pointer: " << rstPtr << std::endl;
	std::cout << "Test pointer: 0x" << std::hex << test << std::dec << std::endl << std::endl;

	std::cout << "Default value: " << dftPtr->value << std::endl;
	std::cout << "Restored value: " << rstPtr->value << std::endl;
	std::cout << "Test value: " << testPtr->value << std::endl;

	return (0);
}
