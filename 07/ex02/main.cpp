#include <iostream>
#include "Array.hpp"

#include "Array.hpp"

int main() {
    try {
        // Test default constructor
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        // Test constructor with size parameter
        Array<int> arr2(5);
        std::cout << "arr2 size: " << arr2.size() << std::endl;

        // Test copy constructor
        Array<int> arr3 = arr2;
        std::cout << "arr3 size: " << arr3.size() << std::endl;
		//Test assignment operator
		arr1 = arr2;
        std::cout << "arr1 size: " << arr1.size() << std::endl;
        // Test element access
        std::cout << "Element at index 2 in arr2: " << arr2[2] << std::endl;
        // Trying to access out of bounds index
        std::cout << "Element at index 10 in arr2: " << arr2[10] << std::endl;
    } catch (const Array<int>::invalidIndexException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
