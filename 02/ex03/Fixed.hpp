#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

#define CONSTRUCTOR "Default constructor called"
#define DESTRUCTOR "Destructor called"
#define COPY_CONSTRUCTOR "Copy constructor called"
#define COPY_ASSIGNMENT "Copy assignment operator called"
#define RAW_BITS "getRawBits member function called"

class Fixed 
{
	public:
	Fixed(); //default constructor
	~Fixed(); //destructor
	Fixed(const int value);
	Fixed(const float value);
	float toFloat(void) const;
	int toInt(void)	const;
	Fixed(const Fixed &other); //copy constructor
	Fixed operator=(const Fixed &other); //copy assignment operator overload 
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator+(const Fixed &rhs) const;
	bool operator-(const Fixed &rhs) const;
	bool operator*(const Fixed &rhs) const;
	bool operator/(const Fixed &rhs) const;
	Fixed min(Fixed &lhs, Fixed &rhs);
	Fixed min(const Fixed &lhs, const Fixed &rhs);
	Fixed max(Fixed &lhs, Fixed &rhs);
	Fixed max(const Fixed &lhs, const Fixed &rhs);
	
	int getRawBits(void) const;
	void setRawBits(const int raw);

	private:
	int RawBits;
	static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &object);

#endif