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

Fixed::Fixed(const int value)
{
	RawBits = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	RawBits =  roundf((value) * (float) (1 << fractionalBits));
}
float Fixed::toFloat(void) const
{
	return (float) ((float) RawBits / (float) (1 << fractionalBits));
}

int Fixed::toInt(void)	const
{
	return RawBits >> fractionalBits;
}

int Fixed::getRawBits(void) const
{
	return this->RawBits;
}

void Fixed::setRawBits(const int raw)
{
	this->RawBits = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if(this == &other)
		return *this;
	RawBits = other.RawBits;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &object)
{
	stream << object.toFloat();
	return stream;
}

