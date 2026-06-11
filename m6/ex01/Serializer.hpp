#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#include "Data.hpp"

class Serializer
{
	public :
		static uintptr_t	Serialize(Data* ptr);
		static Data*		Deserialize(uintptr_t raw);

	private :
		Serializer(void);
		Serializer(const Serializer &cpy);
		~Serializer(void);

		Serializer &operator=(const Serializer &fixed);

};

#endif
