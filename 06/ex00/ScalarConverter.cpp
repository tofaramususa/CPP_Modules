#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const value)
{
	try 
	{
		int tempValue = std::stoi(value);
		if(tempValue < 0 || tempValue > 127)
			throw std::invalid_argument("negative values");
		char charValue = static_cast<char>(tempValue);
		if(!charValue || tempValue < 32 || tempValue == 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << charValue << "'" << std::endl;
	}
    catch (const std::exception& e)
    {
		if(value.size() == 1)
			std::cout << "char: '" << value << "'" << std::endl;
        std::cout << "char: impossible" << std::endl;
    }
    // Handle int
    try {
        int intValue = static_cast<int>(std::stoi(value));
        std::cout << "int: " << intValue << std::endl;
    } 
	catch (const std::exception& e)
	{
        std::cout << "int: impossible" << std::endl;
    }
    // Handle float
    try {
        float floatValue = static_cast<float>(std::stof(value));
        if (value.find('.') == std::string::npos && value != "nan")
		{
            std::cout << "float: " << floatValue << ".0f" << std::endl;
        } else 
		{
            std::cout << "float: " << floatValue << "f" << std::endl;
        }
    } 
	catch (const std::exception& e) 
	{
        std::cout << "float: impossible" << std::endl;
    }
    // Handle double
    try 
	{
        double doubleValue = static_cast<double>(std::stod(value));
        if (value.find('.') == std::string::npos && value != "nan") 
		{
            std::cout << "double: " << doubleValue << ".0" << std::endl;
        } else 
		{
            std::cout << "double: " << doubleValue << std::endl;
        }
    } 
	catch (const std::exception& e) 
	{
        std::cout << "double: impossible" << std::endl;
    }
}
