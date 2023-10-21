#include "Harl.hpp"

Harl::Harl(std::string level)
{
	complain(level);
}

Harl::~Harl()
{
	
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
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
			case 0: (this->debug());
				break ;
			case 1: (this->info());
				break ;
			case 2: (this->warning());
				break ;
			case 3: (this->error());
				break ;
		}
		i++;
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << DEBUG_MESSAGE << std::endl;
}
void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << INFO_MESSAGE << std::endl;

}
void Harl::warning(void)
{
	std::cout << "[ WARNING ]"  << std::endl << WARNING_MESSAGE << std::endl;	
}
void Harl::error(void)
{
	std::cout << "[ ERROR ]"  << std::endl << ERROR_MESSAGE << std::endl;
}