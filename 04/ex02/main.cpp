#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

int main()
{

	const Animal *test[100];
	for(int i = 0; i < 50; ++i)
	{
		test[i] = new Dog();
	}
	for(int i = 50; i < 100; ++i)
	{
		test[i] = new Cat();
	}
	for (int i = 0; i < 100; ++i)
	{
		delete test[i];
	}
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;
	// return 0;
}