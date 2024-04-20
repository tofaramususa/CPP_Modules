#include "Span.hpp"

//need to change this to better tests using different iterators to fill in the numbers
//also need to adjust the using try and catch block
//randomly generate numbers up to 10,000 random numbers
void fillVectorWithRandom(std::vector<unsigned int>& vec, unsigned int size)
{
    std::srand(std::time(0)); // Seed the random number generator

    for (unsigned int i = 0; i < size; ++i)
    {
        unsigned int randomValue = std::rand();
        vec.push_back(randomValue);
    }
}

int main()
{
	Span sp(10020);

	std::vector<unsigned int> values;
	try
	{

		fillVectorWithRandom(values, 100000);
		std::cout << "Size of values added: " << values.size() << std::endl;
		sp.addRange(values.begin(), values.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}