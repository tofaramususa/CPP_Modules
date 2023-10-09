#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) 
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
	return fixed_point;
}

void Fixed::setRawBits(const int raw)
{
	fixed_point = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if(this == &other)
		return *this;
	fixed_point = other.fixed_point;
	std::cout << COPY_ASSIGNMENT << std::endl; 
	return *this;
}

Fixed::Fixed(const int value)
{
	fixed_point = value << fractionalBits;
}
Fixed::Fixed(const float value)
{
	fixed_point = static_cast<int> (value) << fractionalBits;
}
float Fixed::toFloat(void) const
{
	return static_cast<float>(fixed_point >> fractionalBits);
}
int Fixed::toInt(void)	const
{
	return fixed_point >> fractionalBits;
}

int Fixed::getRawBits(void) const
{
	return fixed_point;
}

void Fixed::setRawBits(const int raw)
{
	fixed_point = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if(this == &other)
		return *this;
	fixed_point = other.fixed_point;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &object)
{
	stream << object.toFloat();
}

