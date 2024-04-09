#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <iterator>

template <typename T> //change this to have and take optional container type
class MutantStack : public std::stack<T>
{
	public:
	//Canonical Form here
	MutantStack(){std::stack<T>::c = std::deque<T>();}; //default constructor
	MutantStack(const MutantStack& other) : std::stack<T>(other) {}; //copy constructor
	MutantStack &operator=(MutantStack &other)
	{
		if(this != &other)
		{
			this->c = other.c;
		}
			return *this;
	}//copy assignment
	~MutantStack(){} //destructor

	//iterators
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return(std::stack<T>::c.begin()); };
	iterator end() { return(std::stack<T>::c.end()); };

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const { return(std::stack<T>::c.begin()); };
	const_iterator end() const { return(std::stack<T>::c.end()); };

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin() { return(std::stack<T>::c.rbegin()); };
	reverse_iterator rend() { return(std::stack<T>::c.rend()); };

	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const { return( std::stack<T>::c.rbegin());  };
	const_reverse_iterator rend() const{  return(std::stack<T>::c.rend());  };
};

#endif