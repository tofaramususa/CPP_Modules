#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe &other)
{
	(void) other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe &other)
{
	(void) other;
	return (*this);
}

PmergeMe::PmergeMe(char *argv[]) : listsortingtime(0), dequesortingtime(0)
{
	long	value;
	char	*endPtr;
	clock_t	start;
	clock_t	end;

	std::list<int> arg1;
	std::deque<int> arg2;
	while (argv && *argv)
	{
		value = std::strtol(*argv, &endPtr, 10);
		if (value < 0)
			throw std::invalid_argument("Not a positive integer");
		else if (value > INT_MAX)
			throw std::invalid_argument("Value above max integer");
		arg1.push_back(value);
		arg2.push_back(value);
		++argv;
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < arg2.size(); ++i)
	{
		std::cout << arg2[i] << " ";
	}
	std::cout << std::endl;
	start = std::clock();
	this->sortDeque(arg2);
	end = std::clock();
	this->dequesortingtime = static_cast<double>(end - start)
		/ static_cast<double>(CLOCKS_PER_SEC) * 1000000;
	start = std::clock();
	this->sortList(arg1);
	end = std::clock();
	this->listsortingtime = static_cast<double>(end - start)
		/ static_cast<double>(CLOCKS_PER_SEC) * 1000000;
	std::cout << "After: ";
	for (size_t i = 0; i < arg2.size(); ++i)
	{
		std::cout << arg2[i] << " ";
	}
	std::cout << std::endl;
	printListTime(listsortingtime, arg1.size());
	printDequeTime(dequesortingtime, arg2.size());
}

void	printListTime(double totalTime, int size)
{
	std::cout << "Time to process a range of " << size << " elements with std::list<int> : " << totalTime << " us" << std::endl;
}
void	printDequeTime(double totalTime, int size)
{
	std::cout << "Time to process a range of " << size << " elements with std::deque<int> : " << totalTime << " us" << std::endl;
}

void PmergeMe::sortDeque(std::deque<int> &arg)
{
	int	first;
	int	second;
	int	element;

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arg.size(); i += 2)
	{
		first = arg[i];
		if (i + 1 < arg.size())
		{
			second = arg[i + 1];
		}
		else
		{
			second = -1;
		}
		if (first < second)
		{
			std::swap(first, second);
		}
		pairs.push_back(std::pair<int, int>(first, second));
	}
	std::deque<int> largeNumbers;
	std::deque<int> smallNumbers;
	std::deque<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		largeNumbers.push_back(it->first);
		if (it->second != -1)
			smallNumbers.push_back(it->second);
	}
	if (largeNumbers.size() > 1)
	{
		this->sortDeque(largeNumbers);
	}
	for (std::deque<int>::iterator it = smallNumbers.begin(); it != smallNumbers.end(); ++it)
	{
		element = *it;
		std::deque<int>::iterator insertPos = binarySearch(largeNumbers.begin(),
			largeNumbers.end(), element);
		largeNumbers.insert(insertPos, element);
	}
	arg.swap(largeNumbers);
}

void PmergeMe::sortList(std::list<int> arg)
{
	int	first;
	int	second;
	int	element;

	std::list<std::pair<int, int> > pairs;
	std::list<int>::iterator it1 = arg.begin();
	while (it1 != arg.end())
	{
		first = *it1;
		++it1;
		if (it1 != arg.end())
		{
			second = *it1;
		}
		else
			second = -1;
		if (first < second)
		{
			std::swap(first, second);
		}
		pairs.push_back(std::pair<int, int>(first, second));
		if (it1 != arg.end())
		{
			++it1;
		}
	}
	std::list<int> largeNumbers;
	std::list<int> smallNumbers;
	std::list<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it)
	{
		largeNumbers.push_back(it->first);
		if (it->second != -1)
			smallNumbers.push_back(it->second);
	}
	if (largeNumbers.size() > 1)
	{
		this->sortList(largeNumbers);
	}
	for (std::list<int>::iterator it = smallNumbers.begin(); it != smallNumbers.end(); ++it)
	{
		element = *it;
		std::list<int>::iterator insertPos = binarySearch(largeNumbers.begin(),
			largeNumbers.end(), element);
		largeNumbers.insert(insertPos, element);
	}
	arg.swap(largeNumbers);
}
