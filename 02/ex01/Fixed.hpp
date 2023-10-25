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

	int getRawBits(void) const;
	void setRawBits(const int raw);

	private:
	int RawBits;
	static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &object);

#endif