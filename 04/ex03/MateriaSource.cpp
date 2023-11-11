#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		materiasArray[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor Called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (materiasArray[i] != NULL)
		{
			delete materiasArray[i];
			materiasArray[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i) // cleanup
		{
			if (this->materiasArray[i] != NULL)
			{
				delete this->materiasArray[i];
				this->materiasArray[i] = NULL;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			if (other.materiasArray[i] != NULL)
			{
				this->materiasArray[i] = other.materiasArray[i]->clone();
					// create deep copy
			}
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materiasArray[i] == NULL)
		{
			materiasArray[i] = m;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materiasArray[i] && materiasArray[i]->getType() == type)
			return (materiasArray[i]->clone());
	}
	return (0);
}
