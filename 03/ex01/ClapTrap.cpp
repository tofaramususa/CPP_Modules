#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
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
	std::cout << "ScavTrap named " << _name << " has been created!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(this->Energy > 0)
	{
		std::cout << "ClapTrap " << GetName() << "attacks " << target << ", causing" 
			<< GetDamagePoints() << "points of damage!" << std::endl; 
		this->Energy -= 1;
	}
	else
		std::cout << "Claptrap" << GetName() << " is out of energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->Hit > 0)
	{
		std::cout << "ClapTrap " << GetName() << " takes damage of  " << amount << "points" 
		 << std::endl; 
		 this->Hit -= amount;
	}
	else
		std::cout << "Claptrap " << GetName() << " is out of hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(Hit > 0 && Energy > 0)
	{
		std::cout << "ClapTrap " << GetName() << " has been repaired with  " << amount << "of points" 
		 << std::endl;
		this->Hit += amount;
		this->Energy--;
	}
	else
		std::cout << "Claptrap " << GetName() << " is out of energy points!" << std::endl;
}

unsigned int ClapTrap::GetEnergyPoints() const
{

	std::cout << GETTER << std::endl;
	return this->Energy;
}

unsigned int ClapTrap::GetHitPoints() const
{
	std::cout << GETTER << std::endl;
	return this->Hit;
}

unsigned int ClapTrap::GetDamagePoints() const
{
	std::cout << GETTER << std::endl;
	return this->Damage;
}

std::string ClapTrap::GetName() const
{
	std::cout << GETTER << std::endl;
	return this->Name;
}