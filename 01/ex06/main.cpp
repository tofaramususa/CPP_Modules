#include <iostream>
#include "Harl.hpp"

int main(int ac, char **argv)
{
	if(ac != 2)
	{
		std::cout << "This program takes one parameter only" << std::endl;
		return 1;
	}
	if(argv[1])
	{
		Harl input(argv[1]);
	}
	return 0;
}