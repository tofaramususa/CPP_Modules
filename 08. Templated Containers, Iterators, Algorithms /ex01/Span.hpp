#ifndef SPAN_H
#define SPAN_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <ctime>

class Span
{
	private:
		Span();
		std::vector<unsigned int> integers;
		unsigned int N;

	public:
		Span(unsigned int N);
		~Span(); //destructor
		Span(const Span &other); //copy constructor
		Span& operator=(const Span &other); //copy assignment operator overload 
		void addNumber(unsigned int i);
		int shortestSpan();
		int longestSpan();
		void addRange(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end);
		//then add some kind of range iterators function here
};


#endif