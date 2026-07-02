#include "BitcoinExchange.hpp"

int   errorMsg(std::string msg)
{
    std::cout << msg << std::endl;
    return (1);
}

int     checkFileErrors(std::ifstream &dataFile, std::ifstream &inputFile)
{
     if (!dataFile.is_open())
        return (errorMsg("Error: missing data.csv file"));
     if (!inputFile.is_open())
        return (errorMsg("Error: file doesn't exist."));
    return (0);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (errorMsg("Error: could not open file."));
    
    std::ifstream dataFile("data.csv");
    std::ifstream inFile(argv[1]);

    if (checkFileErrors(dataFile, inFile))
        return (1);
    
    Database source;
    Database input;

    ParseDb(dataFile, source, ',');
    ParseDb(inFile, input, '|');
    AnnoucePrice(source, input);
    return (0);
}