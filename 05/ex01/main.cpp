/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:10 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:06:35 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() 
{
    try 
	{
        Bureaucrat Person("Tofara", 13);
        Form form("Sales", 50, 75);
        Person.signForm(form);
        std::cout << form << std::endl;
        Bureaucrat otherPerson("John", 300);
        otherPerson.signForm(form);
        std::cout << form << std::endl;
    } 
	catch (const std::exception& e) 
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}