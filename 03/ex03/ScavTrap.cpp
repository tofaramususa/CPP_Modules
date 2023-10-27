#include "ScavTrap.hpp"
	
ScavTrap::ScavTrap()
{
	std::string input("Default");
	Name = input;
	std::cout << SCAV_CONSTRUCTOR << std::endl;
	SetHitPoints(100);
	SetEnergyPoints(50);
	SetDamagePoints(20);
}

ScavTrap::ScavTrap(std::string& name) : ClapTrap(name)
{
	std::cout << SCAV_PARAM_CONSTRUCTOR << std::endl;
	std::cout << "ScavTrap named " << name << " has been created!" << std::endl;
	Hit = 100;
	Energy = 50;
	Damage = 20;	
}

ScavTrap::~ScavTrap()
{
	std::cout << SCAV_DESTRUCTOR << std::endl;
};

void ScavTrap::attack(const std::string& target)
{
	if(GetEnergyPoints() > 0 && GetHitPoints() > 0)
	{
		std::cout << "ScavTrap " << GetName() << " attacks " << target << " causing " 
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
		std::cout << "ScavTrap " << GetName() << " is out of energy or hit points!" << std::endl;
}

void ScavTrap::guardGate()
{
		std::cout << "ScavTrap " << GetName() << " is now in Gate Keeper Mode" << std::endl;
}	

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << SCAV_COPY_CONSTRUCTOR << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << SCAV_COPY_ASSIGNMENT << std::endl;
	if(this != &other)
	{
		this->Name = other.GetName();
		this->Hit = other.GetHitPoints();
		this->Energy = other.GetEnergyPoints();
		this->Damage = other.GetDamagePoints();
	}
}