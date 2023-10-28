#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Class Default Constructor Called" << std::endl;
	this->type = "Dog";
	mind = new Brain();
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog Class Parametized Constructor Called" << std::endl;
	this->type = "Dog";
	mind = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Class Destructor Called" << std::endl;
	if(mind)
		delete mind;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Class Copy Constructor Called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << " Dog Class Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		this->type = other.type;
		// this->mind = new mind(other.mind);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog Makes Sound: Bark! Bark!" << std::endl;
}
