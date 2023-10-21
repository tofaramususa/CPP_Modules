#include "Zombie.hpp"

int main()
{
	Zombie *array;

	int total = 10;
	array = zombieHorde(total, "word");

	array->announce();
	for(int i = 0; i < total; ++i)
	{
		array[i].announce();
	}


	delete [] array;
}

