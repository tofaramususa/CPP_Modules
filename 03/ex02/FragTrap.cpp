#include "FragTrap.hpp"
	
FragTrap::FragTrap()
{
	std::cout << FRAG_CONSTRUCTOR << std::endl;
}

FragTrap::FragTrap(std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap Param Constructor Called" << std::endl;
	std::cout << "FragTrap named " << name << " has been created!" << std::endl;
	Hit = 100;
	Energy = 100;
	Damage = 30;	
}

FragTrap::~FragTrap()
{
	std::cout << FRAG_DESTRUCTOR << std::endl;
};

void FragTrap::highFivesGuys(void)
{
		std::cout << "Give me a High Fives ✋!" << std::endl;
}
