#include "PmergeMe.hpp"

std::list<int> checkArguments(char **argv)
{

}

int main(int ac, char **argv)
{

	try
	{
		if(ac < 2)
			throw std::out_of_range("Need at least one argument");
		checkArguments(argv);
		
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//Container l will use - list and deque containers
// RoadMap:
// 1. We need to check if actually an integer, then we need to check is its positive, then we need to check if its equal to or less than int_max
//2. Then we need to do error handling for each step. 
//implement an algorithm for each container: 
// 3. Then we implement an algorithm;
// 4. Okay then we need to print out the message with the TIME - which l don't know;