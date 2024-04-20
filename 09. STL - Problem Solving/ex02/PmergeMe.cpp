#include "PmergeMe.hpp"

// PmergeMe::PmergeMe() {}                       // default
// PmergeMe::PmergeMe(PmergeMe &other) {} // copy
PmergeMe::~PmergeMe() {} //
// destructor PmergeMe &PmergeMe::operator=(PmergeMe
// &other) {

//   return *this;
// } // operator overload


PmergeMe::PmergeMe(char **argv) //constructor
{
	std::list<int> arguments;
	while(argv && *argv)
	{
		long value;
		char *endPtr;
		value = std::strtol(*argv, &endPtr, 10);
		if(endPtr != '\0')
		{
			throw std::invalid_argument("Not a integer value");
		}
		if(value < 0 || value > INT_MAX)
			throw std::invalid_argument("Not a positive integer");
		++argv;
		arguments.push_back(value);
	}
	this->sortList(arguments);
	this->sortDeque(arguments);
}


void PmergeMe::sortDeque(std::list<int> arguments)
{

}
void PmergeMe::sortList(std::list<int> arguments)
{
	
}

