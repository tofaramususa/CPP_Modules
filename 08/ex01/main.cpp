#include "Span.hpp"

//need to change this to better tests using different iterators to fill in the numbers
//also need to adjust the using try and catch block
//randomly generate numbers up to 10,000 random numbers
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}