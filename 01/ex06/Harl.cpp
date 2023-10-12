#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	i = 0;

	while(i < 4 && levels[i] != level)
		i++;
	if (i > 3)
		std::cout << DEFAULT << std::endl;
	while(i < 4)
	{
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
				std::cout << DEFAULT << std::endl;
		}
		i++;
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n" << DEBUG_MESSAGE << std::endl;
}
void Harl::info(void)
{
	std::cout << "[ INFO ]\n" << INFO_MESSAGE << std::endl;

}
void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n" << WARNING_MESSAGE << std::endl;	
}
void Harl::error(void)
{
	std::cout << "[ ERROR ]\n" << ERROR_MESSAGE << std::endl;
}