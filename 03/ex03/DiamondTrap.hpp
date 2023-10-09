#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
	DiamondTrap(std::string &name);
	void whoAmI();
	void attack(const std::string& target);

	private:
	std::string &Name;
};

#endif