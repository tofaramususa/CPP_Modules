#include <iostream>
#include "MutantStack.hpp"

int main() 
{
    MutantStack<int> mstack;
    
    // Push some elements onto the stack
    std::cout << "Pushing elements onto the stack:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        mstack.push(i * 10);
    }
    
    // Print the elements in the stack
    std::cout << "Elements in the stack:" << std::endl;
    for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Access the top element
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    // Pop elements from the stack
    std::cout << "Popping elements from the stack:" << std::endl;
    while (!mstack.empty()) {
        std::cout << mstack.top() << " ";
        mstack.pop();
    }
    std::cout << std::endl;
    
    // Check if the stack is empty
    std::cout << "Is the stack empty? ";
    if (mstack.empty()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    // Push elements onto the stack again
    std::cout << "Pushing elements onto the stack again:" << std::endl;
    for (int i = 5; i >= 1; --i) {
        mstack.push(i * 5);
    }
    
    // Use iterators to print elements in reverse order
    std::cout << "Elements in reverse order:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    // Test copy constructor
    MutantStack<int> mstack_copy = mstack;
    std::cout << "Elements in copied stack:" << std::endl;
    for (MutantStack<int>::const_iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test assignment operator
    MutantStack<int> mstack_assigned;
    mstack_assigned = mstack;
    std::cout << "Elements in assigned stack:" << std::endl;
    for (MutantStack<int>::const_iterator it = mstack_assigned.begin(); it != mstack_assigned.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
