#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

/*
Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

class ICharacter;

class AMateria
{
	protected:
	std::string type;

	public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0; //implemented by concrete classes
	virtual void use(ICharacter& target);
};

#endif