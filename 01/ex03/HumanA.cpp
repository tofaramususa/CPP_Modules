#include "HumanA.hpp"


HumanA::HumanA(const std::string &name, Weapon &weapon) : weapon(&weapon) , name(name)
{
	std::cout << "HumanA Default Constructor called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA Default Destructor called" << std::endl;
}

void HumanA::attack()
{
	std::cout << name << "  attacks with their " << weapon->getType() << std::endl;
}
