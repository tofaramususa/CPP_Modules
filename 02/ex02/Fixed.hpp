#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

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
	Fixed &operator=(const Fixed &other); //copy assignment operator overload 
	/*Increment Operators*/
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	/*Comparison Operators*/
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	/*Arithmetic Operators*/
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;
	/*Overloaded member functions*/
	static Fixed min(Fixed &lhs, Fixed &rhs);
	static Fixed min(const Fixed &lhs, const Fixed &rhs);
	static Fixed max(Fixed &lhs, Fixed &rhs);
	static Fixed max(const Fixed &lhs, const Fixed &rhs);
	
	int getRawBits(void) const;
	void setRawBits(const int raw);

	private:
	int RawBits;
	static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &object);

#endif