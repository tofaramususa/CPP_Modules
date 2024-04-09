#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>
#include <numeric>

class Span
{
	private:
		Span();
		std::vector<int> integers;
		unsigned int N;

	public:
		Span(unsigned int N);
		~Span(); //destructor
		Span(const Span &other); //copy constructor
		Span& operator=(const Span &other); //copy assignment operator overload 
		void addNumber(unsigned int i);
		int shortestSpan();
		int longestSpan();
		//then add some kind of range iterators function here
};


#endif