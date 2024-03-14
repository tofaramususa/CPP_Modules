/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:10 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 15:12:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat *test = new Bureaucrat("test", 5);
        std::cout << *test << std::endl;
        test->increment();
        std::cout << *test << std::endl;
        test->increment();
        std::cout << *test << std::endl;
        test->increment();
        std::cout << *test << std::endl;
        test->increment();
        std::cout << *test << std::endl;
        test->increment();
        std::cout << *test << std::endl;
        test->increment();
        std::cout << *test << std::endl;
        delete test;
    } 
	catch (std::exception& e) 
	{
        std::cout << e.what() << std::endl;
    }
    return 0;
}
