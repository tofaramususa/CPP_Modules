/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:16:05 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:40:15 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Form",target, 25, 5)  { }

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Form", "default", 25, 5) { }


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) 
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) 
	{
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const 
{
	try
	{
		this->isExecuted(executor);
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch (std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}
}
