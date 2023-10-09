#include "Ice.hpp"


Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Class default constructor called" << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type)
{
	std::cout << "Ice Class parameterised constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Class destructor called" << std::endl;	
}

Ice *Ice::clone()
{
	std::cout << "Ice Class clone member function called" << std::endl;
	return new Ice();
}

std::string const &Ice::getType() const
{
	return this->type;
}

Ice::Ice(const Ice &other)
{
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Ice Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
