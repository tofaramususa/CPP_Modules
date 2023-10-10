#include "Cube.hpp"


Cube::Cube() : AMateria("cube"), type("cube")
{
	std::cout << "Cube Class default constructor called" << std::endl;
}

Cube::Cube(std::string const & type) : AMateria(type), type("cube")
{
	std::cout << "Cube Class parameterised constructor called" << std::endl;
}

Cube::~Cube()
{
	std::cout << "Cube Class destructor called" << std::endl;	
}

AMateria *Cube::clone() const
{
	std::cout << "Cube Class clone member function called" << std::endl;
	return new Cube();
}

std::string const &Cube::getType() const
{
	return this->type;
}

Cube::Cube(const Cube &other)
{
	*this = other;
}

Cube &Cube::operator=(const Cube &other)
{
	std::cout << "Cube Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void Cube::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}