#include "ScavTrap.hpp"
	
ScavTrap::ScavTrap()
{
	std::cout << SCAV_CONSTRUCTOR << std::endl;
}

ScavTrap::ScavTrap(std::string& name) : ClapTrap(name)
{
	std::cout << SCAV_PARAM_CONSTRUCTOR << std::endl;
	std::cout << "ScavTrap named " << name << " has been created!" << std::endl;
	Hit = 100;
	Energy = 65;
	Damage = 30;	
}

ScavTrap::~ScavTrap()
{
	std::cout << SCAV_DESTRUCTOR << std::endl;
};

void ScavTrap::attack(const std::string& target)
{
	if(this->Energy > 0)
	{
		std::cout << "ScavTrap " << GetName() << "attacks " << target << ", causing" 
			<< GetDamagePoints() << "points of damage!" << std::endl; 
		this->Energy -= 1;
	}
	else
		std::cout << "ScavTrap" << GetName() << " is out of energy!" << std::endl;	
}

void ScavTrap::guardGate()
{
		std::cout << "ScavTrap " << GetName() << " is now in Gate Keeper Mode" << std::endl;
}	
