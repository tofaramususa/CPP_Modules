#include "HumanB.hpp"


HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << name << "  attacks with their ";
	if(weapon != NULL)
	{
		std::cout << weapon->getType() << std::endl; 
	}		
}