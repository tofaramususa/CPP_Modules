#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie
{
	public:
	Zombie();
	Zombie(const std::string _name);
	~Zombie(void);
	void announce(void);
	void setName(std::string value);

	private:
	std::string name;
};

Zombie *zombieHorde( int N, std::string name );

#endif