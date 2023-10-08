#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

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
	int fixed_point;
	static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &object);

#endif