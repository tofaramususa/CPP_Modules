#ifndef CAT_HPP
#define CAT_HPP


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


class Cat : public Animal
{
	public:
	Cat();
	Cat(std::string type);
	~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	void makeSound() const;

	private:
	Brain *mind;
}; 

#endif