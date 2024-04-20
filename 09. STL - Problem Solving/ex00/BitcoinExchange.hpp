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

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string inputFile); // input the file from the input.txt
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        BitcoinExchange &operator=(BitcoinExchange &other);

    private:
        BitcoinExchange();
        void populateExchangeDatabase();
        void performSearch(std::string inputFile);
        std::map<std::string, double> exchangeRateDB;

        //parsers and error_checking
        void addLineToDatabase(std::vector<std::string> strings);
        void parseLine(std::string line, char delimiter);
        bool isValidValue(std::string &value);
        void checkInputLine(std::vector<std::string> strings);
        bool validateInputLine(std::vector<std::string> strings);
        std::string removeSpaces(std::string line);
        std::map<std::string, double>::iterator getLowestDate(std::string date);
        void checkHeader(std::string line, char delimiter);
        bool checkDate(std::vector<std::string> strings);
};

#endif