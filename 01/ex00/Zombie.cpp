
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string _name) : name(_name)  
{
	std::cout << "Zombie with name " << _name << " created...." << std::endl;
}


void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << ": destroyed........." << std::endl;
}