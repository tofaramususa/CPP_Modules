#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("no_name")
{
	std::cout << CONSTRUCTOR << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << COPY_CONSTRUCTOR << std::endl;
}

ClapTrap ClapTrap::operator=(const ClapTrap &other)
{
	if(this != &other)
	{
		this->Name = other.GetName();
		this->Hit = other.GetHitPoints();
		this->Energy = other.GetEnergyPoints();
		this->Damage = other.GetDamagePoints();
	}
	std::cout << COPY_ASSIGNMENT << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << DESTRUCTOR << std::endl;
}

ClapTrap::ClapTrap(std::string &_name) : Name(_name), Hit(10), Energy(10), Damage(0) 
{
	std::cout << PARAM_CONSTRUCTOR << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(GetEnergyPoints() > 0 && GetHitPoints() > 0)
	{
		std::cout << "ClapTrap " << GetName() << "attacks " << target << ", causing" 
			<< GetDamagePoints() << "points of damage!" << std::endl; 
		takeDamage(GetDamagePoints());
		this->Energy--;
	}
	else
		std::cout << "Claptrap" << GetName() << " is out of energy or hit points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(GetEnergyPoints() > 0 && GetHitPoints() > 0)
	{
		std::cout << "ClapTrap " << GetName() << " takes damage of  " << amount << std::endl; 
		if(GetHitPoints() > amount)
		{
			SetHitPoints(GetHitPoints() - amount);
		}
		else
			SetHitPoints(0);
	}
	else
		std::cout << "Claptrap " << GetName() << " is out of hit or energy points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(GetEnergyPoints() > 0)
	{
		std::cout << "ClapTrap " << GetName() << " has been repaired with  " << amount << "of points" 
		 << std::endl;
		SetHitPoints(GetHitPoints() + amount);
		this->Energy--;
	}
	else
		std::cout << "Claptrap " << GetName() << " is out of energy points!" << std::endl;
}

unsigned int ClapTrap::GetEnergyPoints() const
{

	std::cout << "Get Energy Points Function Called" << std::endl;
	return this->Energy;
}

unsigned int ClapTrap::GetHitPoints() const
{
	std::cout << "Get Hit Points Function Called" << std::endl;
	return this->Hit;
}

unsigned int ClapTrap::GetDamagePoints() const
{
	std::cout << "Get Damage Points Function Called" << std::endl;
	return this->Damage;
}

std::string ClapTrap::GetName() const
{
	std::cout << "Get Name Function Called" << std::endl;
	return this->Name;
}

void ClapTrap::SetEnergyPoints(unsigned int value)
{
	std::cout << "Set Energy Points Function Called" << std::endl;
		this->Energy = value;
}
void ClapTrap::SetHitPoints(unsigned int value)
{
	std::cout << "Set Hit Points Function Called" << std::endl;
	this->Hit = value;
}
void ClapTrap::SetDamagePoints(unsigned int value)
{
	std::cout << "Set Damage Points Function Called" << std::endl;
	this->Damage = value;
}