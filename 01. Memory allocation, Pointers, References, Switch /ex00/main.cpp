#include "Zombie.hpp"


int main()
{
	randomChump("random");
	Zombie newone("going");
	newone.announce();
	Zombie *CR = newZombie("CR");
	CR->announce();
	delete CR;
}