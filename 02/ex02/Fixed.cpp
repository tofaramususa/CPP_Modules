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
	std::cout << "Integer Constructor Called" << std::endl;
	RawBits = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float Constructor Called" << std::endl;
	RawBits =  roundf((value) * (float) (1 << fractionalBits));
}

float Fixed::toFloat(void) const
{
	std::cout << "toFloat Method Called" << std::endl;
	return (float) ((float) RawBits / (float) (1 << fractionalBits));
}

int Fixed::toInt(void)	const
{
	std::cout << "toInt Method Called" << std::endl;
	return RawBits >> fractionalBits;
}

int Fixed::getRawBits(void) const
{
	std::cout << RAW_BITS << std::endl; 
	return this->RawBits;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits Method Called" << std::endl;
	this->RawBits = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if(this == &other)
		return *this;
	this->RawBits = other.RawBits;
	std::cout << COPY_ASSIGNMENT << std::endl; 
	return *this;
}

/*Increment Operators*/
//Pre-increment
Fixed Fixed::operator++()
{
	++this->RawBits;
	return *this;
}

//Pre-decrement
Fixed Fixed::operator--()
{
	--this->RawBits;
	return *this;
}

//Post-increment
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

//Post-decrement
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

/*Comparison Operators*/
bool Fixed::operator==(const Fixed &rhs) const
{
	return this->RawBits == rhs.RawBits;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return !(*this == rhs);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->RawBits < rhs.RawBits;

}

bool Fixed::operator>(const Fixed &rhs) const
{
	return this->RawBits > rhs.RawBits;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return this->RawBits >= rhs.RawBits;

}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return this->RawBits <= rhs.RawBits;

}

/*Arithmetic Operators*/

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return this->toFloat() + rhs.toFloat();
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return this->toFloat() * rhs.toFloat();
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return toFloat() - rhs.toFloat();
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return toFloat() / rhs.toFloat();
}

/*Overloaded member functions*/
Fixed Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return lhs < rhs ? lhs : rhs;
}

Fixed Fixed::min(Fixed const &lhs, const Fixed &rhs)
{
	return lhs < rhs ? lhs : rhs;
}

Fixed Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return lhs > rhs ? lhs : rhs;
}

Fixed Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	return lhs > rhs ? lhs : rhs;
}

std::ostream &operator<<(std::ostream &stream, Fixed const &object)
{
	stream << object.toFloat();
	return stream;
}

void print_boolean(bool value)
{
	if(value)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
}