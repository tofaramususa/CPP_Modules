#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("_clap_name"), Hit(10), Energy(10), Damage(0) 
{
	std::cout << CONSTRUCTOR << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << COPY_CONSTRUCTOR << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::ClapTrap(std::string &_name) : Name(_name + "_clap_name"), Hit(10), Energy(10), Damage(0) 
{
	std::cout << PARAM_CONSTRUCTOR << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(GetEnergyPoints() > 0 && GetHitPoints() > 0)
	{
		std::cout << "ClapTrap " << GetName() << " attacks " << target << " causing " 
			<< GetDamagePoints() << " points of damage!" << std::endl;
		if(GetHitPoints() > GetDamagePoints())
		{
			SetHitPoints(GetHitPoints() - GetDamagePoints());
		}
		else
			SetHitPoints(0);
		this->Energy--;
	}
	else
		std::cout << "Claptrap " << GetName() << " is out of energy or hit points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(GetEnergyPoints() > 0 && GetHitPoints() > 0)
	{
		std::cout << "ClapTrap " << GetName() << " takes damage of  " << amount << std::endl; 
	}
	else
		std::cout << "Claptrap " << GetName() << " is out of energy or hit points!" << std::endl;	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(GetEnergyPoints() > 0)
	{
		std::cout << "ClapTrap " << GetName() << " has been repaired with " << amount << " hit points" 
		 << std::endl;
		SetHitPoints(GetHitPoints() + amount);
		this->Energy--;
	}
	else
		std::cout << "Claptrap " << GetName() << " is out of energy points!" << std::endl;
}

unsigned int ClapTrap::GetEnergyPoints() const
{
	return this->Energy;
}

unsigned int ClapTrap::GetHitPoints() const
{
	return this->Hit;
}

unsigned int ClapTrap::GetDamagePoints() const
{
	return this->Damage;
}

std::string ClapTrap::GetName() const
{
	return this->Name;
}

void ClapTrap::SetEnergyPoints(unsigned int value)
{
		this->Energy = value;
}
void ClapTrap::SetHitPoints(unsigned int value)
{
	this->Hit = value;
}
void ClapTrap::SetDamagePoints(unsigned int value)
{
	this->Damage = value;
}

void ClapTrap::SetName(std::string name)
{
	Name = name;
}