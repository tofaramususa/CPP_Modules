/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:29:56 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 21:10:00 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm.cpp
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Form",
	target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Form", "default",
	72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	try
	{
		this->isExecuted(executor);
		std::srand(std::time(NULL));
		std::cout << "* some drilling noises *" << std::endl;
		if (std::rand() % 2 == 0)
		{
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		}
		else
		{
			std::cout << "Failed to robotomized " << this->getTarget() << std::endl;
		};
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
