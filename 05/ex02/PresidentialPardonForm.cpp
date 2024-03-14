/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:16:05 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 19:45:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// PresidentialPardonForm.cpp
#include "PresidentialPardonForm.hpp"

//name constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Shrubbery Form",target, 25, 5) 
{
	//print
}

//default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Shrubbery Form", "default", 25, 5)
{
	//print
}

//copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) 
{
	*this = other;
}

//assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) 
	{
        AForm::operator=(other);
    }
    return *this;
}

//destructor
PresidentialPardonForm::~PresidentialPardonForm() 
{
	
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const 
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
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

