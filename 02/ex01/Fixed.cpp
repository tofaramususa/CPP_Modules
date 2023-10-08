#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) 
{

}

Fixed::Fixed(const Fixed &other) 
{
	*this = other;
}

Fixed::~Fixed()
{

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

