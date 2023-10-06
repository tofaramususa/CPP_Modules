
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(const std::string _name) : name(_name)  {}


void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie" << name << ": has been destroyed..." << std::endl;
}