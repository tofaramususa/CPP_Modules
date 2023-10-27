#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap Default Constructor Called" << std::endl;
	std::string name("Default");
	this->Name = name;
	this->Hit = FragTrap::Hit;
    this->Energy= ScavTrap::Energy;
    this->Damage = FragTrap::Damage;
}

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(name), FragTrap(name), ScavTrap(name), Name(name)
{
	this->Hit = FragTrap::Hit;
    this->Energy= ScavTrap::Energy;
    this->Damage = FragTrap::Damage;
}


DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	*this = other;
	std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << COPY_ASSIGNMENT << std::endl;
	if(this != &other)
	{

		this->Name = other.Name;
		this->Hit = other.Hit;
		this->Energy = other.Energy;
		this->Damage = other.Damage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond Destructor Called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name: " << getDiamondName() << " | " << "ClapTrap Name: " << GetName() << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

std::string DiamondTrap::getDiamondName()
{
	return this->Name;
}
