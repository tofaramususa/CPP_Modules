#include "RPN.hpp"

int main(int ac, char **av)
{
  try
  {
    if (ac == 2)
    {
        RPN test(av[1]);
        return (1);
    }
    throw std::invalid_argument("Only take 1 input string");
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  return(0);
}
