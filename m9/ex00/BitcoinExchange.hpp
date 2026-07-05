#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define START_YEAR	2009
#define END_YEAR	2026

#define MAX_VALUE	1e3

#define ERR_DATE_OUT_OF_RANGE	"Error: bad input => "
#define ERR_INVALID_FILE 		"Error: could not open file."
#define ERR_TOO_LARGE			"Error: too large a number"
#define ERR_NOT_POSITIVE		"Error: not a positive number"
#define ERR_NO_RATE				"Error: no rate found"
#define ERR_INVALID_SYNTAX		"Error: invalid syntax"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <map>

typedef std::map<int, float> Database;

void	parseDb(std::string filename, Database &out, char c);
void	annoucePrice(Database &src, std::ifstream &input);

#endif
