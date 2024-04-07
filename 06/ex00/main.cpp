#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{

	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return(0);
	}
    ScalarConverter::convert("42");
    ScalarConverter::convert("3.14");
    ScalarConverter::convert("-42.42");
    ScalarConverter::convert("hello");

	return 1;
}

// #include <iostream>
// #include <string>
// #include <cmath> // for INFINITY and NAN

// class ScalarConverter {
// public:
//     static void convert(const std::string& value) {
//         if (value == "-inf" || value == "+inf") {
//             std::cout << "double: " << (value == "-inf" ? -INFINITY : INFINITY) << std::endl;
//             return;
//         }

//         if (value == "nan") {
//             std::cout << "double: " << NAN << std::endl;
//             return;
//         }

//         try {
//             double doubleValue = std::stod(value);
//             std::cout << "double: " << doubleValue << std::endl;
//         } catch (const std::invalid_argument& e) {
//             std::cout << "double: impossible" << std::endl;
//         } catch (const std::out_of_range& e) {
//             std::cout << "double: overflow" << std::endl;
//         }
//     }
// };