#include "Base.hpp"
#include <iostream>

Base::~Base()
{
	std::cout << "Destructor called" << std::endl;
}