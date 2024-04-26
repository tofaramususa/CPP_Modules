#include "PmergeMe.hpp"
#include <stdexcept>

int main(int ac, char **argv)
{
	try
	{
	   ++argv;
		if(ac < 2)
			throw std::out_of_range("Need at least one argument");
		for(int i = 0; i < ac - 1; ++i)
		{
		     if(std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
							throw std::invalid_argument("Not a positive integer");
		}
		PmergeMe sorting(argv);
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
