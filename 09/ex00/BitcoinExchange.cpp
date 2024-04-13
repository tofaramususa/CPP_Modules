#include "BitcoinExchange.hpp"
#include <cmath>
#include <cstdio>

// BitcoinExchange::BitcoinExchange() {}                       // default
// BitcoinExchange::BitcoinExchange(BitcoinExchange &other) {} // copy
BitcoinExchange::~BitcoinExchange() {} //
// destructor BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange
// &other) {

//   return *this;
// } // operator overload

BitcoinExchange::BitcoinExchange(std::string inputData) : inputFile(inputData) {
  try {
    this->populateExchangeDatabase();
    this->performSearch(inputFile);
  } catch (...) {
    // throw() //error here
  }
}

void BitcoinExchange::populateExchangeDatabase() {
  // readfile, and also error handling here
  std::string line;
  std::ifstream data("data.csv");
  try {
    if (data.is_open()) {
      std::getline(data, line);
      this->checkHeader(line, true);
      while (std::getline(data, line)) {
        parseLine(line, ',', true);
        // here is were we add line to our map function split on the comma
      }
      data.close();
    } else {
      if (data.is_open())
        data.close();
      // throw //failed to open data file error
      std::cout << "failed data.csv file" << std::endl;
    }
  } catch (std::exception &e) {
    // return failed to load data error
  }
}

void BitcoinExchange::performSearch(std::string InputFile) {
  std::string line;
  std::ifstream data(InputFile);
  try {
    if (data.is_open()) {
      std::getline(data, line);
      this->checkHeader(line, false);
      while (std::getline(data, line)) {
        line = removeSpaces(line);
        parseLine(line, '|', true);
      }
      data.close();
    } else {
      if (data.is_open())
        data.close();
      std::cout << "failed 2" << std::endl;
    }
  } catch (std::exception &e) {
    // return failed to load data error
  }
}

void BitcoinExchange::validateInputLine(std::vector<std::string> strings) {

  std::tm fullDate;

  if (strings.size() == 2) {
    // check the date if its proper
    if (std::sscanf(strings[0].c_str(), "%4d-%2d-%2d", &fullDate.tm_year,
                    &fullDate.tm_mon, &fullDate.tm_mday) == 3 &&
        isValidValue(strings[1])) {
      if (fullDate.tm_mon > 0 && fullDate.tm_mon < 13 && fullDate.tm_mday > 0 &&
          fullDate.tm_mday < 32) {
        std::map<int, double>::iterator retrieveDate =
            exchangeRateDB.lower_bound(dateToInt(fullDate));
        std::cout << retrieveDate->second * std::atoi(strings[1].c_str())
                  << std::endl;
      } else {
        std::cout << "invalid date 1" << std::endl;
      }
    } else {
      std::cout << "invalid date 2" << std::endl;
    }
  } else {
    // throw error
    std::cout << "invalid date 3" << std::endl;
  }
}
// overall parseline
void BitcoinExchange::parseLine(std::string line, char delimiter,
                                bool dataCSV) // add to map if
{
  std::vector<std::string> strings;
  std::istringstream lineString(removeSpaces(line));
  std::string token;
  while (getline(lineString, token, delimiter)) // create array of strings
  {
    strings.push_back(token);
  }
  if (dataCSV)
    this->addLineToDatabase(strings);
  else
    this->validateInputLine(strings);
  // then add to map and return
  // else search for for the data in data and print accordingly
}

bool BitcoinExchange::isValidValue(std::string &value) {
  char *endPtr;
  double floatValue;
  long intValue;

  if (value.empty())
    return false;
  floatValue = std::strtod(value.c_str(), &endPtr);
  if (*endPtr == '\0' && floatValue >= 0.0 && floatValue <= 1000.0)
    return true;
  intValue = std::strtol(value.c_str(), &endPtr, 10);
  if (*endPtr == '\0' && intValue >= 0 && intValue <= 1000)
    return true;
  return false;
}

// check database line if correct then print value
void BitcoinExchange::addLineToDatabase(std::vector<std::string> strings) {
  // we need a time struct
  std::tm fullDate;

  if (strings.size() == 2) {
    // check the date if its proper
    if (std::sscanf(strings[0].c_str(), "%4d-%2d-%2d", &fullDate.tm_year,
                    &fullDate.tm_mon, &fullDate.tm_mday) == 3 &&
        isValidValue(strings[1])) {
      if (fullDate.tm_mon > 0 && fullDate.tm_mon < 13 && fullDate.tm_mday > 0 &&
          fullDate.tm_mday < 32) {
        this->exchangeRateDB.insert(std::make_pair(
            dateToInt(fullDate), std::strtod(strings[1].c_str(), NULL)));
      }
    }
  } else {
    // throw erro
    std::cout << "failed 3" << std::endl;
  }
}

std::string BitcoinExchange::removeSpaces(std::string line) {
  std::string finalString;

  for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
    if (*it != ' ')
      finalString += *it;
  }
  return (finalString);
}

// use the same function for both
void BitcoinExchange::checkHeader(std::string line, bool dataCSV) {
  std::vector<std::string> strings;
  std::istringstream lineString(removeSpaces(line));
  std::string token;
  if (dataCSV) {
    while (getline(lineString, token, ',')) {
      strings.push_back(token);
    }
    if (strings.size() != 2 || strings[0] != "date" ||
        strings[1] != "exchange_rate") {
      std::cout << "No headers in datafile";
    }
  }
  // check that specific header or throw error
  else {
    while (getline(lineString, token, '|')) {
      strings.push_back(token);
    }
    if (strings.size() != 2 || strings[0] != "date" || strings[1] != "value") {
      std::cout << "No headers in inputfile";
    }
  }
}

int BitcoinExchange::dateToInt(const std::tm &date) {
  int year = date.tm_year + 1900;
  int month = date.tm_mon + 1;
  int day = date.tm_mday;

  return year * 10000 + month * 100 + day;
}
