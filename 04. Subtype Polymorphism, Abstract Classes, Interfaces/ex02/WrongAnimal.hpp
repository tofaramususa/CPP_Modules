#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP


#include <iostream>
#include <string>

/*  
Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/
class WrongAnimal
{
	public:
	WrongAnimal();
	WrongAnimal(std::string type);
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	void makeSound() const;
	std::string getType() const;
	void setType(std::string value);

	protected:
	std::string type;
};

#endif