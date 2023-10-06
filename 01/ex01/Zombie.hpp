#include <iostream>


class Zombie
{
	public:
	Zombie() {}
	Zombie(const std::string _name);
	~Zombie(void);
	void announce(void);

	private:
	std::string name;
};

Zombie *zombieHorde( int N, std::string name );