#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Class Default Constructor Called" << std::endl;
	this->type = "Cat";
	mind = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat Class Parametized Constructor Called" << std::endl;
	this->type = "Cat";
	mind = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Class Destructor Called" << std::endl;
	if(mind)
		delete mind;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy Construcot Called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << " Cat Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat Makes Sound: Meow!" << std::endl;
}