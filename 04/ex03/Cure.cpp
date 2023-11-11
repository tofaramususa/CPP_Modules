#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Class default constructor called" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
	std::cout << "Cure Class parameterised constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Class destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	std::cout << "Cure Class clone member function called" << std::endl;
	return new Cure();
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
