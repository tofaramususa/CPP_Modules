#include "BitcoinExchange.hpp"
#include <stdexcept>

int main(int ac, char **av)
{
  try
  {
    if (ac != 2)
        throw std::invalid_argument("Only take 1 input. Thanks");
    BitcoinExchange(std::string(av[1]));
  }
  catch (std::exception &e)
  {
      std::cerr << e.what() << std::endl;
  }
  catch (...)
  {
      std::cerr << "Error somewhere" << std::endl;
  }
}
