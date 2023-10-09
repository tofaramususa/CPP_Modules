#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(name), FragTrap(name), ScavTrap(name), Name(name)
{
	this->Hit = FragTrap::Hit;
    this->Energy= ScavTrap::Energy;
    this->Damage = FragTrap::Damage;
	ClapTrap::SetName(name + "_clap_name");
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name: " << this->Name << " | " << "ClapTrap Name: " << ClapTrap::GetName() << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}