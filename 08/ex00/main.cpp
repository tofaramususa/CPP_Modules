#include "easyfind.hpp"

//also make use of the tpp file
int main() {
    // Example usage with vector
	std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
       std::vector<int>::iterator result;
	    result = easyfind(vec, 3);
        std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;
    } catch (const std::out_of_range& e) 
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        std::vector<int>::iterator result = easyfind(vec, 6);
        std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;
    } catch (const std::out_of_range& e) 
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
