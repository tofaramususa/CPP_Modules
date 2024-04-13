#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  try {
    if (ac < 2)
      throw(1);
    else if (ac == 2)
      BitcoinExchange(std::string(av[1]));
  } catch (int i) {
    // print message about not enough arguments;
    //  if(i == 1)
    //  	//std::cout << could not read files
    //  else if(i == 2)
    //  	//std::cout << no multiple files
  } catch (...) {
    // print program error
  }
}
