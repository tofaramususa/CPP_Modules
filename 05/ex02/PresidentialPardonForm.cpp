/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:16:05 by marvin            #+#    #+#             */
/*   Updated: 2024/04/06 21:28:53 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// PresidentialPardonForm.cpp
#include "PresidentialPardonForm.hpp"

//name constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Form",target, 25, 5) 
{
	//print
}

//default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Form", "default", 25, 5)
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

