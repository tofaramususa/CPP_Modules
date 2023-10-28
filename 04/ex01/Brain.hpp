#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <iostream>
#include <string>

/*  
Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/
class Brain
{
	public:
	Brain();
	Brain(std::string type);
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	void printIdeas();

	private:
	std::string ideas[100];
};

#endif