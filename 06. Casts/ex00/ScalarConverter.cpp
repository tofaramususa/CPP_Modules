#include "ScalarConverter.hpp"


void ScalarConverter::convert(std::string const value)
{
	try 
	{
		char_cast(value);
	}
    catch (const std::exception& e)
    {
		if(value.size() == 1)
			std::cout << "char: '" << value << "'" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
    }
    try 
	{
        int intValue = static_cast<int>(str_to_float(value));
        std::cout << "int: " << intValue << std::endl;
    } 
	catch (const std::exception& e)
	{
        std::cout << "int: impossible" << std::endl;
    }
    try 
	{
		float_cast(value);
    } 
	catch (const std::exception& e) 
	{
        std::cout << "float: impossible" << std::endl;
    }
    try
	{
		double_cast(value);
    } 
	catch (const std::exception& e) 
	{
        std::cout << "double: impossible" << std::endl;
    }
}
