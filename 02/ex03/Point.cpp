#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::~Point(){}

Point::Point(const Point &other)
{
	*this = other;
}

Point &Point::operator=(const Point &other)
{
	if(this != &other)
	{
		const_cast<Fixed &>(this->x) = other.x;
		const_cast<Fixed &>(this->y) = other.y;
	}
	return *this;
}

const Fixed &Point::getX() const 
{
	return x;
}

const Fixed &Point::getY() const 
{
	return y;
}