#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : materiasArray{NULL,NULL,NULL,NULL}
{
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;	
	*this = other;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor Called" << std::endl;
	for(int i = 0; i < 4; ++i)
	{
		if(materiasArray[i] != NULL)
		{
			delete materiasArray[i];
			materiasArray[i] = NULL;
		}
	}		
}

MateriaSource &MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource Copy Assignment Operator Called" << std::endl;
	if(this != &other)
	{
		for(int i = 0; i < 4; ++i) //cleanup
		{
			if(materiasArray[i] != NULL)
			{
				delete materiasArray[i];
				materiasArray[i] = NULL;
			}
		}
		for(int i = 0; i < 4; ++i)
		{
			if(other.materiasArray[i] != NULL)
			{
				materiasArray[i] = other.materiasArray[i]->clone(); //create deep copy
			}
		}		

	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if(materiasArray[i] == nullptr)
		{
			materiasArray[i] = m->clone();
			return;
		}
	}
}

// void MateriaSource::createMateria(str::string const & type)
// {


// }