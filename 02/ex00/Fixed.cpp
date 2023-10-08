#include "Fixed.hpp"

Fixed::Fixed() : value(0) 
{

}

Fixed::Fixed(const Fixed &other) 
{
	*this = other;
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{
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
	return *this;
}