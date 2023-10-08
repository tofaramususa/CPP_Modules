#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed 
{
	public:
	Fixed(); //default constructor
	~Fixed(); //destructor
	Fixed(const Fixed &other); //copy constructor
	Fixed &operator=(const Fixed &other); //copy assignment operator overload 

	int getRawBits(void) const;
	void setRawBits(const int raw);

	private:
	int value;
	static const int bits = 8;
};

#endif