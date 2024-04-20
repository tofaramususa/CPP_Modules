#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::string input("Default");
	Name = input;
	SetHitPoints(100);
	SetEnergyPoints(100);
	SetDamagePoints(30);
	std::cout << FRAG_CONSTRUCTOR << std::endl;
}

FragTrap::FragTrap(std::string& name) : ClapTrap(name)
{
	std::cout << FRAG_PARAM_CONSTRUCTOR  << std::endl;
	std::cout << "FragTrap named " << name << " has been created!" << std::endl;
	SetHitPoints(100);
	SetEnergyPoints(100);
	SetDamagePoints(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << FRAG_COPY_CONSTRUCTOR << std::endl;
	*this = other;

}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << FRAG_COPY_ASSIGNMENT << std::endl;
	if(this != &other)
	{
		this->Name = other.GetName();
		this->Hit = other.GetHitPoints();
		this->Energy = other.GetEnergyPoints();
		this->Damage = other.GetDamagePoints();
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << FRAG_DESTRUCTOR << std::endl;
};

void FragTrap::highFivesGuys(void)
{
		std::cout << "Give me a High Fives ✋!" << std::endl;
}
