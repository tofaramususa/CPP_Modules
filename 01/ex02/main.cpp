#include <iostream>


int main()
{
	std::string stringVAR = "HI THIS IS BRAIN";

	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout <<  "The memory address of the string variable:" << &stringVAR << std::endl;
	std::cout <<  "The memory address of the stringPTR:" << stringPTR << std::endl;
	std::cout <<  "The memory address of the stringREF:" << &stringREF << std::endl;

	std::cout <<  "The value of the string variable: " << stringVAR << std::endl;
	std::cout <<  "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout <<  "The value referenced to by stringREF: " << stringREF << std::endl;
}