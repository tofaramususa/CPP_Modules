#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Class Default Constructor Called" << std::endl;
	type = "Default Animal";
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal Class Parametized Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Class Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Copy Construcot Called" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << " WrongAnimal Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Makes Sound!" << std::endl;
}

void WrongAnimal::setType(std::string value)
{
	std::cout << "WrongAnimal setType function called" << std::endl;
	type = value;
}

std::string WrongAnimal::getType() const
{
	std::cout << "WrongAnimal getType function called" << std::endl;
	return type;
}
