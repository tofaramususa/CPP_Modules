/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:13:14 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 21:07:27 by tmususa          ###   ########.fr       */
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
    if (this != &other) {}
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) 
{
    static const int NForms = 3;
    const std::string formNames[NForms] = { "shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[NForms] = { new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target) };

    AForm* newForm = NULL;
    for (int i = 0; i < NForms; i++) 
	{
        if (formNames[i] == name) {
            newForm = forms[i];
        } else {
            delete forms[i];
        }
    }

    if (newForm != NULL) 
	{
        std::cout << "Intern creates form " << name << std::endl;
    } 
	else 
	{
        throw Intern::FormNotCreatedException();
    }
    return newForm;
}

const char *Intern::FormNotCreatedException::what() const throw()
{
	return ("Intern was not able to find the form");
}