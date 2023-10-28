#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Class Default Constructor Called" << std::endl;
	type = "Animal";
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal Class Parametized Constructor Called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Class Destructor Called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy Construcot Called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << " Animal Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::setType(std::string value)
{
	type = value;
}

void Animal::makeSound() const
{
	std::cout << "Animal Makes Sound!" << std::endl;
}

