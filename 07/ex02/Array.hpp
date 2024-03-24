#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>

class Array 
{
	public:
		Array(); //default constructor 
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array<T> &operator=(const Array &rhs)


}




#endif