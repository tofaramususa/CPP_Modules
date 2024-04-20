#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <string>

class Point
{
	public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	const Fixed &getX() const;
	const Fixed &getY() const;
	~Point();

	private:
	const Fixed x;
	const Fixed y;
};



#endif