#include "ScalarConverter.hpp"

 static void convert(const std::string& value) 
 {
        try 
		{
            char charValue = static_cast<char>(std::stoi(value));
            std::cout << "char: '" << charValue << "'" << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "char: impossible" << std::endl;
        }

        try {
            int intValue = std::stoi(value);
            std::cout << "int: " << intValue << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "int: impossible" << std::endl;
        }

        try {
            float floatValue = std::stof(value);
            std::cout << "float: " << floatValue << "f" << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "float: impossible" << std::endl;
        }

        try {
            double doubleValue = std::stod(value);
            std::cout << "double: " << doubleValue << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "double: impossible" << std::endl;
        }
    }

