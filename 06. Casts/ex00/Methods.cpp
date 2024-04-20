#include "ScalarConverter.hpp"

bool check_infinities(std::string str)
{
    if (str == "inf" || str == "-inf" || str == "+inf" || str == "-inff" ||
		str == "+inff" || str == "inff" || str == "nan") 
	{
        return true;
    } 
	else 
	{
        return false;
    }
}

float str_to_float(std::string str)
{
    size_t i = 0;
    bool negative = false;
    bool hasDecimal = false;
    float result = 0.0f;
    float decimalMultiplier = 0.1f;

    if (str[0] == '-') 
	{
        negative = true;
        i++;
		if(str[i] == '\0')
			throw std::invalid_argument("Invalid input");
    }
    for (; i < str.length(); i++) 
	{
        if (isdigit(str[i])) 
		{
            if (!hasDecimal) 
			{
                result = result * 10 + (str[i] - '0');
            } else 
			{	
                result += (str[i] - '0') * decimalMultiplier;
                decimalMultiplier *= 0.1f;
            }
        } 
		else if (str[i] == '.' && i != 0) 
		{
            if (hasDecimal || str[i - 1] == '-') 
			{
                throw std::invalid_argument("Invalid input");
            }
            hasDecimal = true;
        }
		 else if (str[i] == 'f' || str[i] == 'F') 
		 {
            if (i != str.length() - 1) 
			{
                throw std::invalid_argument("Invalid input");
            }
        }
		else 
		{
            throw std::invalid_argument("Invalid input");
        }
    }
    if (negative) 
	{
        result = -result;
    }
    return result;
}


void double_cast(std::string const value)
{
	double doubleValue;
	bool suffix = false;

	try
	{
		if(value[value.size() - 1] == 'f' && !check_infinities(value))
			suffix = true;
		if(check_infinities(value))
			doubleValue = std::atof(value.c_str());
		else
			doubleValue = static_cast<double>(str_to_float(value));
		if (value.find('.') == std::string::npos && !check_infinities(value)) 
		{
			std::cout << "double: " << doubleValue << ".0" << std::endl;
		} 
		else 
		{
		if(suffix)
			std::cout << "double: " << value.substr(0, value.size() -1) << std::endl;
		else
			std::cout << "double: " << value << std::endl;
		}
	}
	catch (std::exception &e)
	{
		throw std::invalid_argument("error");
	}
}

void float_cast(std::string const value)
{
	float floatValue;

	try
	{
		std::string suffix = "f";
		if(value[value.size() - 1] == 'f')
		{
			suffix = "";
		}
		if(check_infinities(value))
			floatValue = std::atof(value.c_str());
		else
			floatValue = static_cast<double>(str_to_float(value));

		if (value.find('.') == std::string::npos && !check_infinities(value))
		{
			std::cout << "float: " << floatValue << ".0f" << std::endl;
		} 
		else 
		{
			std::cout << "float: " << value << suffix << std::endl;
		}
	}
	catch (std::exception &e)
	{
		throw std::invalid_argument("error");
	}
}

void char_cast(std::string const value)
{
	try
	{
		int tempValue = str_to_float(value);
		if(tempValue < 0 || tempValue > 127)
			throw std::invalid_argument("negative values");
		char charValue = static_cast<char>(tempValue);
		if(!charValue || tempValue < 32 || tempValue == 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << charValue << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		throw std::invalid_argument("error");
	}
}
