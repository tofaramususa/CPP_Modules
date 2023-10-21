#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	void attack();

	private:
	Weapon *weapon;
	std::string name;

};

#endif