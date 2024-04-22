#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <string>
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <ctime>
#include <deque>
#include <limits>

class PmergeMe
{

    public:
        PmergeMe(char *argv[]);
        ~PmergeMe();
        PmergeMe(PmergeMe &other);
        PmergeMe &operator=(PmergeMe &other);

    private:
        PmergeMe();
        void sortDeque(std::deque<int> &arg);
        void sortList(std::list<int> arg);
        double listsortingtime;
        double dequesortingtime;
};


template<typename iterator, typename T>
iterator binarySearch(iterator start, iterator end, const T& value)
{
    iterator current = start;
    typename std::iterator_traits<iterator>::difference_type range, mid;
    range = std::distance(start, end);
    while(range > 0)
    {
        current = start;
        mid = range / 2;
        std::advance(current, mid);
        if(*current <= value)
        {
            start = ++current;
            range -= mid + 1;
        }
        else
        {
            range = mid;
        }
    }
    return start;
}

#endif
