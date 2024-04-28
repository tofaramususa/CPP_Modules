#include "RPN.hpp"

int main(int ac, char **av)
{
  try
  {
    if (ac == 2)
    {
        RPN test(av[1]);
        return (0);
    }
    throw std::invalid_argument("Only takes excutable and one argument");
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
	return (1);
  }
  return(0);
}
