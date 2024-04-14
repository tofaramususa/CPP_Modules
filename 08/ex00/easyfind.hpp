#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator itr = std::find(container.begin(), container.end(), value);
	 if(itr == container.end()) 
	 {
		throw std::out_of_range("No value found");
	 }
	 return(itr);
}

#endif