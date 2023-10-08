#include "FileProcessor.hpp"


int main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " filename s1 s2" << std::endl;
		return 1;
	}

FileProcessor file(av[1], av[2], av[3]);

if(file.processFile())
{
	std::cout << "File successfully processed. " << std::endl;
}
else
{
	std::cerr << "Error: File processing failed. " << std::endl;
	return 1;
}
return 0;

}