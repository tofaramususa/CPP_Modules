#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cube : AMateria
{
	private:
	std::string type;

	public:
	Cube();
	Cube(std::string const & type);
	Cube(const Cube &other);
	Cube &operator=(const Cube &other);
	virtual ~Cube();

	std::string const & getType() const; //Returns the materia type

	AMateria* clone() const;
	
	virtual void use(ICharacter& target);
};

#endif