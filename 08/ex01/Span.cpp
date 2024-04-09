#include "Span.hpp"

//parameter constructor
Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other) : N(other.N)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other) 
	{
        N = other.N;
        integers.clear();
        integers.reserve(other.integers.size());
        std::copy(other.integers.begin(), other.integers.end(), std::back_inserter(integers));
	}
	return(*this);
}


Span::~Span() {}

int Span::shortestSpan()
{
	if (integers.size() <= 1) 
	{
		throw std::logic_error("Insufficient data to calculate span");
	}
	std::vector<int> sortedIntegers = integers;
    std::sort(sortedIntegers.begin(), sortedIntegers.end());
	return(std::abs(*(integers.begin() + 1) - *integers.begin()));
}

int Span::longestSpan()
{
	if (integers.size() <= 1) 
	{
		throw std::logic_error("Insufficient data to calculate span");
	}
	return(*std::max_element(integers.begin(), integers.end()) - *std::min_element(integers.begin(), integers.end()));
}

void Span::addNumber(unsigned int i)
{
	if (integers.size() >= N) 
	{
		throw std::out_of_range("Span is full");
	}
	integers.push_back(i);
}