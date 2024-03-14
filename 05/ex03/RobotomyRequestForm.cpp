/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:29:56 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 19:49:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// RobotomyRequestForm.cpp
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Shrubbery Form",target, 25, 5) 
{
	//print
}

//default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Shrubbery Form", "default", 25, 5)
{
	//print
}

//copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) 
{
	*this = other;
}

//assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) 
	{
        AForm::operator=(other);
    }
    return *this;
}

//destructor
RobotomyRequestForm::~RobotomyRequestForm() 
{
	
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const 
{
	if (!isSigned()) 
	{
		throw FormNotSignedException();
	}
	else if (this->getSignGrade() < executor.getGrade()) 
	{
		std::cout << "Form  cannot be executed because the rank is too low" << std::endl;
		throw GradeTooLowException();
	}
	else
	{
		std::srand(std::time(NULL)); // use current time as seed for random generator

		std::cout << "* some drilling noises *" << std::endl;
		if (std::rand() % 2 == 0) {
			std::cout << this->getTarget() << " has been robotomized succesfully" << std::endl;
		} else 
		{
			std::cout << "Failed to robotomized " << this->getTarget() << std::endl;
		}
	}
}

