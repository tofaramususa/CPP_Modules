#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) 
{

}

Fixed::Fixed(const Fixed &other) : fixed_point(other.fixed_point) 
{
	
}

Fixed::~Fixed()
{

}

Fixed::Fixed(const int value) : fixed_point(value << fractionalBits)
{}
Fixed::Fixed(const float value) : fixed_point(static_cast<int> (value) << fractionalBits)
{}

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

Fixed Fixed::operator=(const Fixed &other)
{
	if(this == &other)
		return *this;
	fixed_point = other.fixed_point;
	return *this;
}

Fixed Fixed::operator++()
{
	this->fixed_point += 1;
	return *this;
}

Fixed Fixed::operator--()
{
	this->fixed_point -= 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return fixed_point == rhs.fixed_point;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return !(*this == rhs);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return fixed_point < rhs.fixed_point;

}

bool Fixed::operator>(const Fixed &rhs) const
{
	return fixed_point > rhs.fixed_point;

}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return fixed_point >= rhs.fixed_point;

}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return fixed_point <= rhs.fixed_point;

}

bool Fixed::operator+(const Fixed &rhs) const
{
	return toFloat() + rhs.toFloat();
}

bool Fixed::operator*(const Fixed &rhs) const
{
	return toFloat() * rhs.toFloat();
}

bool Fixed::operator-(const Fixed &rhs) const
{
	return toFloat() - rhs.toFloat();
}

bool Fixed::operator/(const Fixed &rhs) const
{
	return toFloat() / rhs.toFloat();
}

Fixed Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return lhs < rhs ? lhs : rhs;
}

Fixed Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	return lhs < rhs ? lhs : rhs;
}

Fixed Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return lhs > rhs ? lhs : rhs;
}

Fixed Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	return lhs > rhs ? lhs : rhs;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &object)
{
	stream << object.toFloat();
}
