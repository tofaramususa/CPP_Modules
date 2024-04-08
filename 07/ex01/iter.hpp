#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename Func>
void iter(T *array, std::size_t size, Func f)
{
	if(!array || !size || !f)
	{
		std::cout << "Invalid Argument" << std::endl;
		return ;
	}
	for (std::size_t i = 0; i < size; ++i)
	{
		f(array[i]);
	}
}

//test template function
template <typename T>
void printItem(T value)
{
	std::cout << value << std::endl;
}

#endif