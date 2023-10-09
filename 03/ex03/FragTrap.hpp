#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#define FRAG_CONSTRUCTOR "FragTrap Default constructor called"
#define FRAG_DESTRUCTOR "FragTrap Destructor called"
#define FRAG_COPY_CONSTRUCTOR "FragTrap Copy constructor called"
#define FRAG_COPY_ASSIGNMENT "FragTrap Copy assignment operator called"
#define FRAG_GETTER "FragTrap Getter function called"
#define FRAG_PARAM_CONSTRUCTOR "FragTrap Parameterized constructor called"

class FragTrap : virtual public ClapTrap
{
	public:
	FragTrap();
	FragTrap(std::string& name);
	~FragTrap();
	void highFivesGuys(void);	
};

#endif
