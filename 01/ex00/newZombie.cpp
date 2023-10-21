
#include <iostream>
#include "Zombie.hpp"

 Zombie *newZombie(std::string name)
 {
	Zombie *zombie = new Zombie(name);
	std::cout << "New allocated Zombie Object created" << std::endl;
	return (zombie);
 }

