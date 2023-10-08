#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	i = 0;

	while(i < 0 && levels[i] != level)
		i++;
	switch(i)
	{
		case 0: (this->*funcs[i])();
			break ;
		case 1: (this->*funcs[i])();
			break ;
		case 2: (this->*funcs[i])();
			break ;
		case 3: (this->*funcs[i])();
			break ;
		default:
			std::cout << "The following comments are accepted DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << DEBUG_MESSAGE << std::endl;
}
void Harl::info(void)
{
	std::cout << INFO_MESSAGE << std::endl;

}
void Harl::warning(void)
{
	std::cout << WARNING_MESSAGE << std::endl;	
}
void Harl::error(void)
{
	std::cout << ERROR_MESSAGE << std::endl;
}