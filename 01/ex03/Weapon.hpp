#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon 
{
	private:
	std::string type;

	public:
	Weapon(const std::string &type);
	Weapon(void);
	~Weapon(void);
	const std::string &getType() const;
	void setType(const std::string &newType);
};

#endif