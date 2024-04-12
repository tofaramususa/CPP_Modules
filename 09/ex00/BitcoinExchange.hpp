#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstdlib> 

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string inputData); //input the file from the input.txt
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange &other);
		BitcoinExchange &operator=(BitcoinExchange &other);

	private:
		BitcoinExchange();
		void populateExchangeDatabase();
		void performSearch(std::string inputFile);
		void validateLine(std::string line);
		void retrieveRate(std::string date);
		void addLineToDatabase(std::vector<std::string> strings);
		void validateInputValue(std::string value);
		void parseLine(std::string line, char delimiter, bool dataCSV);
		std::string removeSpaces(std::string line);

		std::map<std::tm, double> exchangeRateDB; //this will store the exchangeRates
		std::string inputFile
};	

//override a stream that outputs the values
// 2011-01-03 => 3 = 0.9
#endif