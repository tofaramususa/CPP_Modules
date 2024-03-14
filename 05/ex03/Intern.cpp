/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:13:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 20:30:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() 
{
	
}

Intern::Intern(const Intern& other) 
{
    (void)other;
}

Intern::~Intern()
{
	
}

Intern& Intern::operator=(const Intern& other) 
{
    if (this != &other) 
	{
		
    }
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) 
{
    static const int NForms = 3;
    const std::string formNames[NForms] = { "shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[NForms] = { new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target) };

    AForm* ret = NULL;
    for (int i = 0; i < NForms; i++) {
        if (formNames[i] == name) {
            ret = forms[i];
        } else {
            delete forms[i];
        }
    }

    if (ret != NULL) 
	{
        std::cout << "Intern creates form " << name << std::endl;
    } else 
	{
        std::cout << "Intern was not able to find the form " << name << std::endl;
    }
    return ret;
}

