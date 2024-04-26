#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
    if(this != &other)
    {
        this->exchangeRateDB = other.exchangeRateDB;
    }
  return *this;
}

BitcoinExchange::BitcoinExchange(std::string inputFile)
{
  try
  {
    this->populateExchangeDatabase();
    this->performSearch(inputFile);
  } catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}

void BitcoinExchange::populateExchangeDatabase()
{
  std::string line;
  std::ifstream data("data.csv", std::ifstream::in); //handle case where there is no data.csv
  try
  {
    if (data.is_open())
    {
      std::getline(data, line); // check the header here
      this->checkHeader(line, ',');
      while (std::getline(data, line))
      {
        parseLine(line, ',');
      }
      data.close();
    }
  } catch (std::exception &e)
  {
    if (data.is_open())
      data.close();
    std::cout << e.what() << std::endl;
  }
}

void BitcoinExchange::performSearch(std::string InputFile)
{
  std::string line;
  std::ifstream data(InputFile.c_str(), std::ifstream::in);
  try {
    if (data.is_open())
    {
      std::getline(data, line);
      this->checkHeader(line, '|');
      while (std::getline(data, line)) {
        parseLine(line, '|');
      }
      data.close();
    }
  } catch (std::exception &e)
  {
    if (data.is_open())
      data.close();
    std::cout << e.what() << std::endl;
  }
}

bool BitcoinExchange::checkDate(std::vector<std::string> strings)
{
  std::tm fullDate;
  std::vector<std::string> dateStrings;
  std::string token;

  if (!strings.size())
  {
    return (false);
  }
  std::istringstream lineString(strings[0]);
  while (getline(lineString, token, '-'))
  {
    dateStrings.push_back(token);
  }
  if (dateStrings.size() != 3 || dateStrings[0].size() != 4 ||
      dateStrings[1].size() != 2 || dateStrings[2].size() != 2)
  {
    return (false);
  }
  if (std::sscanf(strings[0].c_str(), "%4d-%2d-%2d", &fullDate.tm_year,
                  &fullDate.tm_mon, &fullDate.tm_mday))
  {
    if (fullDate.tm_mon > 0 && fullDate.tm_mon < 13 && fullDate.tm_mday > 0 &&
        fullDate.tm_mday < 32 && fullDate.tm_year > 1900 &&
        fullDate.tm_year < 2050)
    {
      return (true);
    }
  }
  return (false);
}

bool BitcoinExchange::validateInputLine(std::vector<std::string> strings) {

  if (strings.size() != 2 && strings.size())
  {
    std::cout << "Error: bad input => " << strings[0] << std::endl;
    return (false);
  }
  if (checkDate(strings) && isValidValue(strings[1])) {
    return (true);
  } else if (strings.size()) {
    std::cout << "Error: bad input => " << strings[0] << std::endl;
  }
  return (false);
}

void BitcoinExchange::checkInputLine(std::vector<std::string> strings) {
  try {
    if (this->validateInputLine(strings)) {
      std::map<std::string, double>::iterator retrieveDate =
          this->getLowestDate(strings[0]);
      std::cout << strings[0] << " => " << strings[1] << " = "
                << retrieveDate->second * strtod(strings[1].c_str(), NULL)
                << std::endl;
    }
  } catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}

void BitcoinExchange::parseLine(std::string line, char delimiter)
{
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

bool BitcoinExchange::isValidValue(std::string &value)
{
  char *endPtr;
  double floatValue;

  if (value.empty())
    return false;
  try {
    floatValue = std::strtod(value.c_str(), &endPtr);
  } catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return (false);
  }
  if (*endPtr != '\0')
    throw std::invalid_argument("Error: not a number");
  else if (floatValue > 1000.0)
    throw std::invalid_argument("Error: too large a number");
  else if (floatValue < 0.0)
    throw std::invalid_argument("Error: not a positive number");
  return (true);
}

void BitcoinExchange::addLineToDatabase(std::vector<std::string> strings) {
  std::tm fullDate;

  if (strings.size() == 2)
  {
    if (std::sscanf(strings[0].c_str(), "%4d-%2d-%2d", &fullDate.tm_year,
                    &fullDate.tm_mon, &fullDate.tm_mday) == 3) {
      if (fullDate.tm_mon > 0 && fullDate.tm_mon < 13 && fullDate.tm_mday > 0 &&
          fullDate.tm_mday < 32) {
        this->exchangeRateDB.insert(std::make_pair(strings[0], std::strtod(strings[1].c_str(), NULL)));
      }
    }
  }
  // else
  // {
  //   std::cout << "failed to add line to exchange rate database" << std::endl;
  // }
}

std::string BitcoinExchange::removeSpaces(std::string line)
{
  std::string finalString;
  finalString.reserve(line.size());

  for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
    if (!std::isspace(static_cast<unsigned char>(*it)))
      finalString.push_back(*it);
  }
  return (finalString);
}

void BitcoinExchange::checkHeader(std::string line, char delimiter)
{
  std::vector<std::string> strings;
  std::istringstream lineString(removeSpaces(line));
  std::string token;

  while (getline(lineString, token, delimiter))
  {
    strings.push_back(token);
  }
  if (delimiter == ',')
  {
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
BitcoinExchange::getLowestDate(std::string date)
{
  std::map<std::string, double>::iterator it;

  it = exchangeRateDB.lower_bound(date);
  if ((it != exchangeRateDB.end() && it->first == date) ||
      it == exchangeRateDB.begin()) {
    return it;
  }
  --it;
  return it;
}
