#include "BitcoinExchange.hpp"

//______________________PARSE________________________

// static void printDb(const Database &db)
// {
//     for (Database::const_iterator it = db.begin(); it != db.end(); ++it)
//     {
//         std::cout << it->first << " -> " << it->second << std::endl;
//     }
	
// }

static std::pair<std::string, int> parseLine(const std::string &line, char c)
{
    std::string::size_type id = line.find(c);
    std::string key = line.substr(0, id);
    int 		value = std::atoi(line.substr(id + 1).c_str());

    return (std::pair<std::string, int>(key, value));
}

void	ParseDb(std::ifstream &file, Database &out, char c)
{	
    std::string header;
    std::getline(file, header);

	for (std::string line; std::getline(file, line); ) 
	{
		out.insert(parseLine(line, c));
	}
}

//______________________COMPARE________________________

void    checkDate(const std::string &date)
{
    std::string::size_type id = date.find(',');

    int year = std::atoi(date.substr(0, id).c_str());
    if (year < 2009 || year > 2026)
        throw (std::runtime_error("Error: bad input => " + date));
    int month = std::atoi(date.substr(id + 1, ))
}

void    AnnoucePrice(Database &src, Database &in)
{
    (void)src;
    for (Database::const_iterator it = in.begin(); it != in.end(); ++it)
    {
        // std::cout << it->first << " -> " << it->second << std::endl;
        try 
        {
            checkDate(it->first);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

