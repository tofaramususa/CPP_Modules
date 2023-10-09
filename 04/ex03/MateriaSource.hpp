#ifndef MateriaSource_HPP
#define MateriaSource_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
	AMateria *materiasArray[4];

	public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();
	void learnMateria(AMateria *m) override;
	AMateria *createMateria(std::string const & type) override;

};

#endif