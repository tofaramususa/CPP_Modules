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
