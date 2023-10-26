#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//dont forget to add this:
/*  
Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
	DiamondTrap();
	virtual ~DiamondTrap();
	DiamondTrap(std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap operator=(const DiamondTrap &other);

	void whoAmI();
	void attack(const std::string& target);

	private:
	std::string &Name;
};

#endif