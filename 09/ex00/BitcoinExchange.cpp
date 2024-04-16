#include "BitcoinExchange.hpp"

// BitcoinExchange::BitcoinExchange() {}                       // default
// BitcoinExchange::BitcoinExchange(BitcoinExchange &other) {} // copy
BitcoinExchange::~BitcoinExchange() {} //
// destructor BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange
// &other) {

//   return *this;
// } // operator overload

BitcoinExchange::BitcoinExchange(std::string inputFile) {
  try {
    this->populateExchangeDatabase();
    this->performSearch(inputFile);
  } catch (...) {
    // throw() //error here
  }
}

void BitcoinExchange::populateExchangeDatabase() {
  std::string line;
  std::ifstream data("data.csv");
  try {
    if (data.is_open()) {
      std::getline(data, line); // check the header here
      this->checkHeader(line, ',');
      while (std::getline(data, line)) {
        parseLine(line, ',');
      }
      data.close();
    }
  } catch (std::exception &e) {
    if (data.is_open())
      data.close();
    std::cout << e.what() << std::endl;
  }
}

void BitcoinExchange::performSearch(std::string InputFile) {
  std::string line;
  std::ifstream data(InputFile);
  try {
    if (data.is_open()) {
      std::getline(data, line);
      this->checkHeader(line, '|');
      while (std::getline(data, line)) {
        parseLine(line, '|');
      }
      data.close();
    }
  } catch (std::exception &e) {
    if (data.is_open())
      data.close();
    std::cout << e.what() << std::endl;
  }
}

bool BitcoinExchange::validateInputLine(std::vector<std::string> strings) {
  std::tm fullDate;

  if (strings.size() != 2) {
    std::cout << "Error : bad input => " << strings[0]
              << std::endl; // potential segfault
    return (false);
  }
  if (std::sscanf(strings[0].c_str(), "%4d-%2d-%2d", &fullDate.tm_year,
                  &fullDate.tm_mon, &fullDate.tm_mday) == 3 &&
      isValidValue(strings[1])) {
    if (fullDate.tm_mon > 0 && fullDate.tm_mon < 13 && fullDate.tm_mday > 0 &&
        fullDate.tm_mday < 32) {
      return (true);
    }
  }
  std::cout << "Error : bad input => " << strings[0]
            << std::endl; // potential segfault
  return (false);
}

void BitcoinExchange::checkInputLine(std::vector<std::string> strings) {

  if (this->validateInputLine(strings)) {
    std::map<std::string, double>::iterator retrieveDate =
        this->getLowestDate(strings[0]);
    std::cout << strings[0] << " => " << strings[1] << " = "
              << retrieveDate->second * strtod(strings[1].c_str(), NULL)
              << std::endl;
  }
}

void BitcoinExchange::parseLine(std::string line, char delimiter) {
  std::vector<std::string> strings;
  std::istringstream lineString(removeSpaces(line));
  std::string token;
  while (getline(lineString, token, delimiter)) // create array of strings
  {
    strings.push_back(token);
  }
  if (delimiter == ',')
    this->addLineToDatabase(strings);
  else
    this->checkInputLine(strings);
}

bool BitcoinExchange::isValidValue(std::string &value) {
  char *endPtr;
  double floatValue;

  if (value.empty())
    return false;
  try {
    floatValue = std::strtod(value.c_str(), &endPtr);
  } catch (...) {
    std::cout << "Not a number" << std::endl;
    return (false);
  }
  if (*endPtr != '\0') {
    std::cout << "Error: not a number";
    return (false);
  } else if (floatValue > 1000.0) {
    std::cout << "Error: too large a number" << std::endl;
    return (false);
  } else if (floatValue < 0.0) {
    std::cout << "Error: not a positive number" << std::endl;
    return (false);
  }
  return (true);
}

void BitcoinExchange::addLineToDatabase(std::vector<std::string> strings) {
  std::tm fullDate;

  if (strings.size() == 2) {
    if (std::sscanf(strings[0].c_str(), "%4d-%2d-%2d", &fullDate.tm_year,
                    &fullDate.tm_mon, &fullDate.tm_mday) == 3) {
      if (fullDate.tm_mon > 0 && fullDate.tm_mon < 13 && fullDate.tm_mday > 0 &&
          fullDate.tm_mday < 32) {
        this->exchangeRateDB.insert(
            std::make_pair(strings[0], std::strtod(strings[1].c_str(), NULL)));
      }
    }
  } else {
    std::cout << "failed to add line to exchange rate database" << std::endl;
  }
}

std::string BitcoinExchange::removeSpaces(std::string line) {

  std::string finalString;
  finalString.reserve(line.size());

  for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
    if (!std::isspace(static_cast<unsigned char>(*it)))
      finalString.push_back(*it);
  }
  return (finalString);
}

// use the same function for both
void BitcoinExchange::checkHeader(std::string line, char delimiter) {
  std::vector<std::string> strings;
  std::istringstream lineString(removeSpaces(line));
  std::string token;

  while (getline(lineString, token, delimiter)) {
    strings.push_back(token);
  }

  if (delimiter == ',') {
    if (strings.size() != 2 || strings[0] != "date" ||
        strings[1] != "exchange_rate") {
      throw std::invalid_argument("No headers in datafile");
    }
  } else if (strings.size() != 2 || strings[0] != "date" ||
             strings[1] != "value") {
    throw std::invalid_argument("No headers in inputfile");
  }
}

std::map<std::string, double>::iterator
BitcoinExchange::getLowestDate(std::string date) {
  std::map<std::string, double>::iterator it;

  it = exchangeRateDB.lower_bound(date);
  if (it != exchangeRateDB.end() && it->first == date) {
    return it;
  }
  if (it == exchangeRateDB.end()) {
    --it;
    return it;
  }
  if (it == exchangeRateDB.begin()) {
    return it;
  }
  --it;
  return it;
}
