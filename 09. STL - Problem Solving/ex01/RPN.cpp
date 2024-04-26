#include "RPN.hpp"

RPN::RPN()
{

}
RPN::RPN(RPN &other)
{
    (void) other;
}
RPN::~RPN()
{

}

RPN &RPN::operator=(RPN &other)
{
    (void) other;
    return *this;
}

RPN::RPN(const std::string &argument)
{
  try
  {
    std::string input = removeSpaces(argument);
    this->checkInput(input);
    this->calculate(input);
  } catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}

void RPN::checkInput(std::string input)
{
  if (input.size() < 3)
  {
    throw std::invalid_argument("Error");
  }
  for (std::string::iterator it = input.begin(); it != input.end(); ++it)
  {
    if (!std::isdigit(*it) && *it != '*' && *it != '+' && *it != '-' && *it != '/')
    {
      throw std::invalid_argument("Error");
    }
  }
}

void RPN::calculate(std::string input)
{
    int operand1;
    int operand2;

  std::stack<int> stack;
  for (std::string::iterator it = input.begin(); it != input.end(); ++it)
  {
    if (std::isdigit(*it))
      stack.push(*it - '0');
    else if (*it == '*' || *it == '+' || *it == '-' || *it == '/')
    {
        if(stack.size() < 2)
        {
            throw std::invalid_argument("Error");
        }
        operand1 = stack.top();
        stack.pop();
        operand2 = stack.top();
        stack.pop();
        stack.push(operation(operand1, operand2, *it));
    }
  }
  if (stack.size() != 1)
  {
    throw std::invalid_argument("Error");
  }
  std::cout << stack.top() << std::endl;
}

std::string RPN::removeSpaces(std::string line)
{

  std::string finalString;
  finalString.reserve(line.size());

  for (std::string::iterator it = line.begin(); it != line.end(); ++it)
  {
    if (!std::isspace(static_cast<unsigned char>(*it)))
      finalString.push_back(*it);
  }
  return (finalString);
}

int RPN::operation(int operand1, int operand2, char c)
{
    int result = 0;

    if(c == '+')
        result = operand1 + operand2;
    else if(c == '-')
    {
        result = operand2 - operand1;
    }
    else if(c == '/')
    {
        result = operand2 / operand1;
    }
    else if(c == '*')
    {
        result = operand1 * operand2;
    }
    return result;
}
