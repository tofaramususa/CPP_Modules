#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : AMateria
{
	private:
	std::string type;

	public:
	Cure();
	Cure(std::string const & type);
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	virtual ~Cure();

	std::string const & getType() const; //Returns the materia type
	AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif