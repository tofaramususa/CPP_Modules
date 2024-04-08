#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <class T>
class Array 
{
	private:
		T *array;
		int length;
	public:
		//default constructor
		Array() : array(NULL), length(0) {};
		//
		Array(unsigned int length) : length(length)
		{
			array = new T[length];
		}
		//copy constructor
		Array(const Array &other) : array(new T[other.length]), length(other.length)
		{
			for (int i = 0; i < length; i++)
				array[i] = other.array[i];
		}
		//copy assignment
		Array& operator=(const Array &other)
		{
			if (this == &other)
				return (*this);
			delete [] array;
			array = new T[other.size()];
			length = other.size();
			for (int i = 0; i < length; i++)
				array[i] = other.array[i];
			return (*this);
		}

		//overload the [] operator
		T &operator[](int i)
		{
			if(i < 0 || i >= length)
				throw invalidIndexException();
			return(array[i]);
		}
		//virtual destructor
		~Array() {delete [] array;};
		int size() const {return (length);};

		//create exception
		class invalidIndexException : public std::exception 
		{
			public:
				virtual const char* what() const throw (){return "Inaccessible Item";}; 
		};
};

#endif