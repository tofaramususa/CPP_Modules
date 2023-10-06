//implement Zombie Class with name
//member function announce (void)
//function to create newZombie
//create 
#include <iostream>

class Zombie
{
	public:
	Zombie(const std::string _name);
	~Zombie(void);
	void announce(void);

	private:
	std::string name;

};

 Zombie *newZombie( std::string name);
 void randomChump( std::string name );