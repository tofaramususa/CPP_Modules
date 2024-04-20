#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <list>
#include <deque>

class PmergeMe
{

	public:
		PmergeMe(char **argv);
		~PmergeMe();
		PmergeMe(PmergeMe &other);
		PmergeMe &operator=(PmergeMe &other);

	private:
		PmergeMe();
		void sortDeque(std::list<int> arguments);
		void sortList(std::list<int> arguments);
		std::list<std::pair<int, int>> List;
		std::deque<std::pair<int, int>> Deque;
};

#endif
