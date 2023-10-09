#include "Fixed.hpp"

Fixed::Fixed() : value(0) 
{
	std::cout << CONSTRUCTOR << std::endl; 

}

Fixed::Fixed(const Fixed &other) 
{
	*this = other;
	std::cout << COPY_CONSTRUCTOR << std::endl; 
}

Fixed::~Fixed()
{
	std::cout << DESTRUCTOR << std::endl; 

}

int Fixed::getRawBits(void) const
{
	std::cout << RAW_BITS << std::endl; 
	return value;
}

void Fixed::setRawBits(const int raw)
{
	value = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if(this == &other)
		return *this;
	value = other.value;
	std::cout << COPY_ASSIGNMENT << std::endl; 
	return *this;
}