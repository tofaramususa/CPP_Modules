#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	i = 0;
	while(i < 4 && levels[i] != level)
		i++;
	switch(i)
	{
		case 0: (this->debug());
			break ;
		case 1: (this->info());
			break ;
		case 2: (this->warning());
			break ;
		case 3: (this->error());
			break ;
		default:
			std::cout << "The following comments are accepted DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << "DEBUG_MESSAGE" << std::endl;
}
void Harl::info(void)
{
	std::cout << "INFO_MESSAGE" << std::endl;

}
void Harl::warning(void)
{
	std::cout << "WARNING_MESSAGE" << std::endl;	
}
void Harl::error(void)
{
	std::cout << "ERROR_MESSAGE" << std::endl;
}