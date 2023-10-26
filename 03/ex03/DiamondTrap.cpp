#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	*this = other;
	std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
}

DiamondTrap DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << COPY_ASSIGNMENT << std::endl;
	if(this != &other)
	{
		this->Name = other.GetName();
		this->Hit = other.GetHitPoints();
		this->Energy = other.GetEnergyPoints();
		this->Damage = other.GetDamagePoints();
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor Called" << std::endl;
}

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