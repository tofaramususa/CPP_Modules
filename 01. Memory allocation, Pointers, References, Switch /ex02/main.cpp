#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"
int main()
{
	std::string stringVAR = "HI THIS IS BRAIN";

	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout <<  "The memory address of the string variable: " << GREEN << &stringVAR << RESET << std::endl;
	std::cout <<  "The memory address of the stringPTR: " << GREEN << stringPTR << RESET << std::endl;
	std::cout <<  "The memory address of the stringREF: " << GREEN << &stringREF << RESET << std::endl;

	std::cout <<  "The value of the string variable: " << GREEN <<  stringVAR << RESET << std::endl;
	std::cout <<  "The value pointed to by stringPTR: " << GREEN << *stringPTR << RESET << std::endl;
	std::cout <<  "The value referenced to by stringREF: " << GREEN << stringREF << RESET << std::endl;
}
