#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define CONSTRUCTOR "Default constructor called"
#define DESTRUCTOR "Destructor called"
#define COPY_CONSTRUCTOR "Copy constructor called"
#define COPY_ASSIGNMENT "Copy assignment operator called"
#define PARAM_CONSTRUCTOR "Parameterized constructor called"

#include <iostream>
#include <string>

/*  
Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

class ClapTrap
{

	public:
	ClapTrap(std::string &_name); //Parameter Constructor
	ClapTrap(); //Default Constructor
	~ClapTrap(); //Default Destructor
	ClapTrap(const ClapTrap &other); //Copy Constructor
	ClapTrap operator=(const ClapTrap &other); //Copy Assignment Operator
	unsigned int GetEnergyPoints() const;
	unsigned int GetHitPoints() const;
	unsigned int GetDamagePoints() const;
	void SetEnergyPoints(unsigned int value);
	void SetHitPoints(unsigned int value);
	void SetDamagePoints(unsigned int value);
	std::string GetName() const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	private:
	std::string Name;
	unsigned int Hit;
	unsigned int Energy;
	unsigned int Damage;
};


#endif