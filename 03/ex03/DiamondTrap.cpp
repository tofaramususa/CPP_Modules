#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), Name()
{
	std::cout << "DiamondTrap Default Constructor Called" << std::endl;
	std::string name("Default");
	std::cout << "DiamondTrap with name " << name << " created!" << std::endl;
	this->Name = name;
	this->Hit = FragTrap::Hit;
    this->Energy= ScavTrap::Energy;
    this->Damage = FragTrap::Damage;
}

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(name), FragTrap(name), ScavTrap(name), Name(name)
{
	std::cout << "DiamondTrap Parameterized Constructor Called" << std::endl;
	std::cout << "DiamondTrap with name " << name << " created!" << std::endl;
	this->Hit = FragTrap::Hit;
    this->Energy= ScavTrap::Energy;
    this->Damage = FragTrap::Damage;
}


DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other) , ScavTrap(other)
{
	std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
	*this = other;
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

std::string DiamondTrap::getDiamondName() const
 {
        return this->Name;
 }
 
unsigned int DiamondTrap::getDiamondHit() const
{
       return this->Hit;
}
unsigned int DiamondTrap::getDiamondEnergy() const
{
       return this->Energy;
}

unsigned int DiamondTrap::getDiamondDamage() const
{
       return this->Damage;
}

std::ostream &operator<<(std::ostream &stream, const DiamondTrap &object)
{
       stream << "Object " << object.GetName() << " has hit points: " << object.getDiamondHit() << " ,energy points: "
       << object.getDiamondEnergy() << " and attack damage " << object.getDiamondDamage();
       return stream;
}
