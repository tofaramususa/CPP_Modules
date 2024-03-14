/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:10 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 20:07:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() 
{
    try {
        // Create bureaucrats
        Bureaucrat john("John", 149); // Grade 10
        Bureaucrat alice("Alice", 130); // Grade 5

        // Create forms
        ShrubberyCreationForm homeForm("home");
        RobotomyRequestForm robotomyForm("target");
        PresidentialPardonForm pardonForm("Zaphod Beeblebrox");

        // Execute forms
        john.executeForm(homeForm);
        alice.executeForm(robotomyForm);
        john.executeForm(pardonForm);

    } 
	catch (const std::exception& e) 
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
