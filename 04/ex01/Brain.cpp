#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Class Default Constructor Called" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		ideas[i] = "Idea";
	}
}

Brain::Brain(std::string idea)
{
	std::cout << "Brain Class Parametized Constructor Called" << std::endl;
	for(int i = 0; i < 100; ++i)
	{
			ideas[i] = idea;
	}
}

Brain::~Brain()
{
	std::cout << "Brain Class Destructor Called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Construcot Called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << " Brain Copy Assignment Operator Called" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return *this;
}

void Brain::printIdeas()
{
	for(int i = 0; i < 100; i++)
	{
		if(!ideas[i].empty())
			std::cout << i + 1 << ": " << ideas[i] << std::endl;
	}
}
