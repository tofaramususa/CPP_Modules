/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:10 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 21:09:18 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() 
{
	Intern Stacy;
    try 
	{
        Bureaucrat Tofara("Tofara", 1);
		Intern Rebecca;
		AForm *newForm;
		
		newForm = Rebecca.makeForm("robotomy request", "Bender");
		Tofara.signForm(*newForm);
        Tofara.executeForm(*newForm);
		if(newForm)
			delete newForm;
    } 
	catch (const std::exception& e) 
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}