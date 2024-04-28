#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
  try
  {
    if (ac != 2)
        throw std::invalid_argument("Only takes excutable and one argument");
    BitcoinExchange(std::string(av[1]));
  }
  catch (std::exception &e)
  {
      std::cerr << e.what() << std::endl;
	  return(1);
  }
  catch (...)
  {
    std::cerr << "Error with data.csv or the input file does not exist" << std::endl;
	return(1);
  }
  return(0);
}
