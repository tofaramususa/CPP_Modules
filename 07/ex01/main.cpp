#include "iter.hpp"

int main() 
{
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Integer array elements: " << std::endl;
    iter(intArray, 5, printItem<int>);
    std::cout << std::endl;

    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Double array elements: " << std::endl;
    iter(doubleArray, 5, printItem<double>);
    std::cout << std::endl;

    // Test with an array of strings
    std::string stringArray[] = {"apple", "banana", "orange"};
    std::cout << "String array elements: " << std::endl;
    iter(stringArray, 3, printItem<std::string>);
    std::cout << std::endl;

    return 0;
}