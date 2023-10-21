#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie default constructor called" << std::endl;
}

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

void Zombie::setName(std::string value)
{
	this->name = value;
}
