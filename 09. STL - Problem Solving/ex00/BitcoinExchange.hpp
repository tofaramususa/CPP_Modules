#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <stdexcept>

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string inputFile);
        ~BitcoinExchange();

    private:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        BitcoinExchange &operator=(BitcoinExchange &other);
        void populateExchangeDatabase();
        void performSearch(std::string inputFile);
        std::map<std::string, double> exchangeRateDB;

        void addLineToDatabase(std::vector<std::string> strings);
        void parseLine(std::string line, char delimiter);
        bool isValidValue(std::string &value);
        void checkInputLine(std::vector<std::string> strings);
        bool validateInputLine(std::vector<std::string> strings);
        std::string removeSpaces(std::string line);
        std::string strtrim(std::string line);
        std::map<std::string, double>::iterator getLowestDate(std::string date);
        void checkHeader(std::string line, char delimiter);
        bool checkDate(std::vector<std::string> strings);
};

#endif
