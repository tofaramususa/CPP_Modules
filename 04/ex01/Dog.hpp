#ifndef DOG_HPP
#define DOG_HPP


#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"


/*  
Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/


class Dog : public Animal
{
	public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog(std::string type);
	Dog operator=(const Dog &other);
	void makeSound() const;

	private:
	Brain *brain;
};


#endif