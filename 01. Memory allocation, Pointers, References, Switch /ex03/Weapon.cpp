#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Weapon Default Constructor called" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon Default Destructor called" << std::endl;
}

Weapon::Weapon(const std::string &type) : type(type)
{
	std::cout << "Weapon Paramaterized Constructor called" << std::endl;
}

const std::string &Weapon::getType()
{
	return type;
}

void Weapon::setType(const std::string &newType)
{
	Weapon::type = newType;
}