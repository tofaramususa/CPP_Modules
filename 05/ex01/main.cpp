/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:10 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 16:51:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() 
{
    try 
	{
        Bureaucrat bureaucrat("John", 13);
        Form form("Tax Form", 50, 75);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
        Bureaucrat lowGradeBureaucrat("Jane", 120);
        lowGradeBureaucrat.signForm(form);
        std::cout << form << std::endl;
    } 
	catch (const std::exception& e) 
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}


