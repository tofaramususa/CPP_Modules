#include "Fixed.hpp"

Fixed::Fixed() : RawBits(0) 
{
	std::cout << CONSTRUCTOR << std::endl; 

}

Fixed::Fixed(const Fixed &other) 
{
	std::cout << COPY_CONSTRUCTOR << std::endl; 
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << DESTRUCTOR << std::endl; 

}

int Fixed::getRawBits(void) const
{
	std::cout << RAW_BITS << std::endl; 
	return RawBits;
}

void Fixed::setRawBits(const int raw)
{
	RawBits = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if(this == &other)
		return *this;
	RawBits = other.RawBits;
	std::cout << COPY_ASSIGNMENT << std::endl; 
	return *this;
}
