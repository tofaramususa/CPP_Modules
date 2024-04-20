/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:10 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 19:56:39 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	*test;
	Bureaucrat	*test2;

	test = new Bureaucrat("NULL", 1);
	test2 = new Bureaucrat("NULL", 150);
	std::cout << *test << std::endl;
	try
	{
		test->increment();
		test2->decrement();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test;
	delete test2;
	return (0);
}
