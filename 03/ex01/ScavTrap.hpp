#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

#define SCAV_CONSTRUCTOR "SvacTrap Default constructor called"
#define SCAV_DESTRUCTOR "SvacTrap Destructor called"
#define SCAV_COPY_CONSTRUCTOR "SvacTrap Copy constructor called"
#define SCAV_COPY_ASSIGNMENT "SvacTrap Copy assignment operator called"
#define SCAV_GETTER "SvacTrap Getter function called"
#define SCAV_PARAM_CONSTRUCTOR "SvacTrap Parameterized constructor called"

//Need to implement othodox canonical form

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap();
	ScavTrap(std::string& name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();	
};

#endif
