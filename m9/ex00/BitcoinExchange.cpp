#include "BitcoinExchange.hpp"

//______________________UTILS________________________

static std::string	iDateToString(int date)
{
	std::stringstream ss;

	int	year = date / 10000;
	int	month = (date / 100) % 100;
	int	day = date % 100;

	ss << year << "-" << std::setw(2) << std::setfill('0')
	<< month << "-" << std::setw(2) << std::setfill('0') << day;
	return (ss.str());
}

//______________________PARSING________________________

static std::pair<int, float>	parseLine(const std::string &line, char c)
{
	std::string::size_type ldSep = line.find('-');
	std::string::size_type rdSep = line.find_last_of('-');
	std::string::size_type valSep = line.find_last_of(c);

	if (ldSep == std::string::npos || rdSep == std::string::npos 
		|| ldSep == rdSep || valSep == std::string::npos)
	return (std::pair<int, float>(-1, -1));

	int		year = std::atoi(line.substr(0, ldSep).c_str());
	int		month = std::atoi(line.substr(ldSep + 1, rdSep - ldSep - 1).c_str());
	int		day = std::atoi(line.substr(rdSep + 1, valSep - rdSep - 1).c_str());
	float	value = std::atof(line.substr(valSep + 1).c_str());

	return (std::pair<int, float>(year * 10000 + month * 100 + day, value));
}

void	parseDb(std::string filename, Database &out, char c)
{
	std::ifstream	file(filename.c_str());
	std::string		header;
	int				invalid_nb = 0;

	if (!file.is_open())
		throw (std::runtime_error(ERR_INVALID_FILE));
	std::getline(file, header);
	for (std::string line; std::getline(file, line);)
	{
		std::pair<int, float> pair = parseLine(line, c);
		if (pair.first == -1 && pair.second == -1)
		{
			invalid_nb++;
			continue;
		}
		out.insert(pair);
	}
	if (invalid_nb > 0)
		std::cerr << "*" << invalid_nb << " invalid line in " << filename << "*" << std::endl;
}

//______________________CHECKING________________________

static void	checkDate(int date)
{
	int	year = date / 10000;
	int	month = (date / 100) % 100;
	int	day = date % 100;
	if (year < START_YEAR || year > END_YEAR
		|| month < 1 || month > 12
		|| day < 1 || day > 31)
		throw (std::runtime_error(ERR_DATE_OUT_OF_RANGE + iDateToString(date)));
}

static void	checkValue(float value)
{
	if (value < 0)
		throw (std::runtime_error("Error: not a positive number"));
	if (value > MAX_VALUE)
		throw (std::runtime_error("Error: too large a number"));
}

//______________________ANNOUNCE_PRICE________________________

static float	findRate(int dateToFind, Database &db)
{
	Database::iterator it = db.lower_bound(dateToFind);

	if (it != db.end() && it->first == dateToFind)
		return (it->second);
	if (it == db.begin())
		throw (std::runtime_error("Error: no rate found"));
	--it;
	return (it->second);
}

void	annoucePrice(Database &src, std::ifstream &input)
{
	std::string header;
	std::getline(input, header);

	for (std::string line; std::getline(input, line);)
	{
		try
		{
			std::pair<int, float> pair = parseLine(line, '|');
			if (pair.first == -1 && pair.second == -1)
				throw (std::runtime_error("Error: invalid syntax"));
			checkDate(pair.first);
			checkValue(pair.second);
			float price = findRate(pair.first, src) * pair.second;
			std::cout << iDateToString(pair.first) << " => " << pair.second  << " = " << price << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
