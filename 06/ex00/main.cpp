#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		return(0);
	}
	ScalarConverter::convert("\n");
	std::cout << std::endl;
    ScalarConverter::convert("3.14");
	std::cout << std::endl;
    ScalarConverter::convert("-42.42");
	std::cout << std::endl;
    ScalarConverter::convert("hello");
	return 1;
}