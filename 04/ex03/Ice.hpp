#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Ice : public AMateria
{

	public:
	Ice();
	Ice(std::string const & type);
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	virtual ~Ice();

	std::string const & getType() const; //Returns the materia type

	Ice* clone();
	
	virtual void use(ICharacter& target);
};

#endif