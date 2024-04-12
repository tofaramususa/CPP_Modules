#ifndef SCALARCONVERTER
# define SCALARCONVERTER

# include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <stdexcept>

//casting functions
void double_cast(std::string const value);
void float_cast(std::string const value);
void char_cast(std::string const value);

class ScalarConverter
{
	public:
		static void convert(std::string const value);

	private:
		ScalarConverter();
};

bool check_infinities(std::string str);
float str_to_float(std::string str);


#endif