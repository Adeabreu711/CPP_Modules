#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

typedef std::map<std::string, float> Database;

void	ParseDb(std::ifstream &file, Database &out, char c);
void    AnnoucePrice(Database &src, Database &in);

#endif
