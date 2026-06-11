#include "Serializer.hpp"

//___________________CONSTRUCTORS___________________

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer &cpy)
{
	*this = cpy;
}

//___________________DESTRUCTORS___________________

Serializer::~Serializer(void)
{
}

//____________________OVERLOADS____________________

Serializer& Serializer::operator=(const Serializer &cpy)
{
	(void)cpy;
	return (*this);
}

//____________________FUNCTIONS____________________

uintptr_t	Serializer::Serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::Deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
