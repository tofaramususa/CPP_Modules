#include "FileProcessor.hpp"


int main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cout << "Program takes exactly THREE arguments. Thanks" << std::endl;
		return 1;
	}

FileProcessor file(av[1], av[2], av[3]);

if(file.processFile())
{
	std::cout << "File successfully processed. " << std::endl;
}
else
{
	std::cout << "Error: File processing failed. " << std::endl;
	return 1;
}
return 0;

}