#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
	Cure();
	Cure(std::string const & type);
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif