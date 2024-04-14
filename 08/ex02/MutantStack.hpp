#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack(){std::stack<T>::c = std::deque<T>();};
	MutantStack(const MutantStack& other) : std::stack<T>(other) {};
	MutantStack &operator=(MutantStack &other)
	{
		if(this != &other)
		{
			this->c = other.c;
		}
			return *this;
	}
	~MutantStack(){}

	//iterators
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return(std::stack<T>::c.begin()); };
	iterator end() { return(std::stack<T>::c.end()); };

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return(std::stack<T>::c.rbegin()); };
	reverse_iterator rend() { return(std::stack<T>::c.rend()); };
};
#endif