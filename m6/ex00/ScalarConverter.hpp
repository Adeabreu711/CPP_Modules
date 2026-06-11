#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

enum ScalarType
{
	SPECIAL_TYPE,
	CHAR_TYPE,
	INT_TYPE,
	DOUBLE_TYPE,
	FLOAT_TYPE,
	INVALID_TYPE
};

struct TypeInfo
{
	ScalarType	type;
	double		value;
	std::string	special;
};

class ScalarConverter
{
	public :
		static void Convert(const std::string &str);

	private :
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &cpy);
		~ScalarConverter(void);

		ScalarConverter &operator=(const ScalarConverter &fixed);
};

#endif
