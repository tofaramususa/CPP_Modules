#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP


#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

/*  
Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

class WrongCat : public WrongAnimal
{
	public:
	WrongCat();
	WrongCat(std::string type);
	~WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
}; 

#endif