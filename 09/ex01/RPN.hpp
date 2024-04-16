#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
    public:
    RPN(const std::string &argument);
    ~RPN();
    RPN(RPN &other);
    RPN &operator=(RPN &other);
    void calculate(std::string input);

    private:
    RPN();
    void checkInput(std::string);
    std::string removeSpaces(std::string value);
    int operation(int operand1, int operand2, char c);
};

#endif
