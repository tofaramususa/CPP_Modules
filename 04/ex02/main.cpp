#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

//Evaluation Questions:
//Shallow Copy and Deep Copy and why they are the case
//why should the constructor do a deep copy too
//Ask an explanation of what will happen without the virtual keyword over Animal destructor.
//
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
	Dog test2;
	{
		Dog tmp = test2;
	}
	test2.getBrain()->printIdeas();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	return 0;
}
