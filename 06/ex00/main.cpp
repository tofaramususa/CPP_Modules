#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	ScalarConverter *a = new ScalarConverter;

	if(argc == 2)
	{
		a->convert(argv[1]);
		return(0);
	}
	std::cout << "Error!" << std::endl;
	return 1;
}