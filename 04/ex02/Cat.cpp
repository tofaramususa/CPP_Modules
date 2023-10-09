#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Class Default Constructor Called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat Class Parametized Constructor Called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Class Destructor Called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy Construcot Called" << std::endl;
	*this = other;
}

Cat Cat::operator=(const Cat &other)
{
	std::cout << " Cat Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		this->type = other.type;
		if(this->brain != NULL)
		{
			delete this->brain;
		}
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {

	std::cout << "Cat Makes Sound: Meow!" << std::endl;
}