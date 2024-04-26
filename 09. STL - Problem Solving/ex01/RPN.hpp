#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>
#include <stdexcept>

class RPN
{
    public:
    RPN(const std::string &argument);
    ~RPN();

    private:
    void calculate(std::string input);
    RPN();
    RPN(RPN &other);
    RPN &operator=(RPN &other);
    void checkInput(std::string);
    std::string removeSpaces(std::string value);
    int operation(int operand1, int operand2, char c);
};

#endif
