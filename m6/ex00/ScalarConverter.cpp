#include "ScalarConverter.hpp"
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cfloat>

//___________________CONSTRUCTORS___________________

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	*this = cpy;
}

//___________________DESTRUCTORS___________________

ScalarConverter::~ScalarConverter(void)
{
}

//____________________OVERLOADS____________________

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	return (*this);
}

//_______________CHECK_TYPE_FUNCTIONS_______________

static bool IsDisplayable(char c)
{
	return (c >= 32 && c <= 126);
}

static bool IsSpecialType(const std::string &str)
{
	return
	(
		str == "-inf" || str == "+inf" ||
		str == "-inff" || str == "+inff" ||
		str == "nan" || str == "nanf"
	);
}

static bool IsCharType(const std::string &str)
{
	return (str.length() == 1 && !isdigit(str[0]));
}

static int GetNumberType(const std::string &str)
{
	size_t i = 0;
	const size_t len = str.length();

	if (i < len && (str[i] == '+' || str[i] == '-'))
		i++;
	if (i >= len || !std::isdigit(str[i]))
		return (-1);
	while (i < len && std::isdigit(str[i]))
		i++;
	if (i == len)
		return (INT_TYPE);
	if (str[i] == '.')
	{
		i++;
		while (i < len && std::isdigit(str[i]))
			i++;
		if (i == len)
			return (DOUBLE_TYPE);
		if (str[i] == 'f' && i + 1 == len)
			return (FLOAT_TYPE);
	}
	return (-1);
}

static ScalarType	GetScalarType(const std::string &str)
{
	int	numberType;

	if (IsSpecialType(str))
		return (SPECIAL_TYPE);
	if (IsCharType(str))
		return (CHAR_TYPE);
	numberType = GetNumberType(str);
	if (numberType != -1)
		return (static_cast<ScalarType>(numberType));
	return (INVALID_TYPE);

}

//__________________PARSE_FUNCTIONS__________________

static TypeInfo	ParseType(const std::string &str)
{
	TypeInfo p = {GetScalarType(str), 0.0, ""};

	if (p.type == SPECIAL_TYPE)
	{
		if (str == "nanf")
			p.special = "nan";
		else if (str == "-inff")
			p.special = "-inf";
		else if (str == "+inff")
			p.special = "+inf";
		else
			p.special = str;
	}
	else if (p.type == CHAR_TYPE)
		p.value = static_cast<double>(str[0]);
	else
		p.value = std::atof(str.c_str());
	return (p);
}

//__________________PRINT_FUNCTIONS__________________

static void PrintChar(TypeInfo &type)
{
	std::cout << "char: ";
	if (type.type == SPECIAL_TYPE || type.value < 0 || type.value > 255)
		std::cout << "impossible";
	else if (!IsDisplayable(static_cast<char>(type.value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(type.value) << "'";
	std::cout << std::endl;
}

static void PrintInt(TypeInfo &type)
{
	std::cout << "int: ";
	if (type.type == SPECIAL_TYPE)
		std::cout << "impossible";
	else if (type.value < INT_MIN || type.value > INT_MAX)
		std::cout << "overflow";
	else
		std::cout << static_cast<int>(type.value);
	std::cout << std::endl;
}

static void PrintFloat(TypeInfo &type)
{
	std::cout << "float: ";
	if (type.type == SPECIAL_TYPE)
		std::cout << type.special << "f" << std::endl;
	else if (type.value < -FLT_MAX || type.value > FLT_MAX)
		std::cout << "overflow" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1)
		<< static_cast<float>(type.value) << "f" << std::endl;
}

static void PrintDouble(TypeInfo &type)
{
	std::cout << "double: ";
	if (type.type == SPECIAL_TYPE)
		std::cout << type.special << std::endl;
	else if (type.value < -DBL_MAX || type.value > DBL_MAX)
		std::cout << "overflow" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << type.value << std::endl;
}

void	ScalarConverter::Convert(const std::string &str)
{
	TypeInfo type = ParseType(str);

	if (type.type == INVALID_TYPE)
	{
		std::cout << "Error: invalid input" << std::endl;
		return ;
	}
	PrintChar(type);
	PrintInt(type);
	PrintFloat(type);
	PrintDouble(type);
}
