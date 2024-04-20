/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:10 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:45:53 by tmususa          ###   ########.fr       */
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
        Bureaucrat Tofara("Tofara", 1);
        Bureaucrat Rebecca("Alice", 12);

        // Create forms
        ShrubberyCreationForm homeForm("home");
        RobotomyRequestForm robotomyForm("target");
        PresidentialPardonForm pardonForm("Zaphod Beeblebrox");

		//sign Forms
		Tofara.signForm(homeForm);
		Rebecca.signForm(robotomyForm);
		Tofara.signForm(pardonForm);

        // Execute forms
        Tofara.executeForm(homeForm);
        Rebecca.executeForm(robotomyForm);
        Tofara.executeForm(pardonForm);

    } 
	catch (const std::exception& e) 
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
