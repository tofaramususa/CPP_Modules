#include "Character.hpp"

Character::Character() : name("Start"), inventory{NULL, NULL, NULL, NULL}
{
	std::cout << "Character Default Constructor Called" << std::endl;
}

Character::Character(const std::string &name) : name(name), inventory{NULL, NULL,NULL, NULL}
{
	std::cout << "Character Parameterized Constructor Called" << std::endl;	
}

Character::Character(const Character &other)
{
	std::cout << "Character Copy Constructor Called" << std::endl;	
	*this = other;
}

Character::~Character()
{
	std::cout << "Character Destructor Called" << std::endl;
	for(int i = 0; i < 4; ++i)
	{
		if(inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}		
}

Character &Character::operator=(const Character& other)
{
	std::cout << "Character Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		name = other.name;
		for(int i = 0; i < 4; ++i) //cleanup
		{
			if(inventory[i] != NULL)
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		for(int i = 0; i < 4; ++i)
		{
			if(other.inventory[i] != NULL)
			{
				inventory[i] = other.inventory[i]->clone(); //create deep copy
			}
		}		

	}
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for(int i = 0; i < 4; ++i)
	{
		if(inventory[i] == NULL)
		{
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if(idx < 0 || idx > 3 || inventory[idx] == NULL)
	{
		return;
	}
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if(idx < 0 || idx > 3 || inventory[idx] == NULL)
	{
		return;
	}
	inventory[idx]->use(target);
}