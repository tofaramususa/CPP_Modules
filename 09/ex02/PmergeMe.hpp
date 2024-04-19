#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

class PmergeMe {

public:
  // PmergeMe()// this will be the parameter constructor;
  ~PmergeMe();
  PmergeMe(PmergeMe &other);
  PmergeMe &operator=(PmergeMe &other);

private:
  PmergeMe();
};

#endif
