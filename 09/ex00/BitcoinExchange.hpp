#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class BitcoinExchange {
public:
  BitcoinExchange(std::string inputFile); // input the file from the input.txt
  ~BitcoinExchange();
  BitcoinExchange(BitcoinExchange &other);
  BitcoinExchange &operator=(BitcoinExchange &other);

private:
  BitcoinExchange();
  void populateExchangeDatabase();
  void addLineToDatabase(std::vector<std::string> strings);
  void parseLine(std::string line, char delimiter);
  void performSearch(std::string inputFile);
  bool isValidValue(std::string &value);
  void checkInputLine(std::vector<std::string> strings);
  bool validateInputLine(std::vector<std::string> strings);
  std::string removeSpaces(std::string line);
  std::map<std::string, double>::iterator getLowestDate(std::string date);
  void checkHeader(std::string line, char delimiter);

  std::map<std::string, double>
      exchangeRateDB; // this will store the exchangeRates
};

// override a stream that outputs the values
//  2011-01-03 => 3 = 0.9
#endif
