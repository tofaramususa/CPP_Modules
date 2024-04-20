#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>

/*  
Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/
class Animal
{
	public:
	Animal();
	Animal(std::string type);
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual void makeSound() const = 0;
	std::string getType() const;
	void setType(std::string value);

	protected:
	std::string type;
};

#endif