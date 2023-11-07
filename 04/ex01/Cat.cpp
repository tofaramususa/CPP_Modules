#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Class Default Constructor Called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat Class Parametized Constructor Called" << std::endl;
	this->type = "Cat";
	brain = new Brain(type);
}

Cat::~Cat()
{
	std::cout << "Cat Class Destructor Called" << std::endl;
	if(brain)
		delete brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << " Cat Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat Makes Sound: Meow!" << std::endl;
}