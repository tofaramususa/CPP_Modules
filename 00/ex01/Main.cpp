/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:45:46 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/10 14:26:08 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(int ac, char **argv)
{
	PhoneBook Book;
	std::string line;
	
	std::cout << "* WELCOME TO THE PHONEBOOK *" << std::endl;
	while (1)
	{
		std::cout << "ENTER ANY OF THE FOLLOWING [ADD] [SEARCH] [EXIT]:" << std::endl;
		std::getline (std::cin,line);
		if(line == "ADD")
			Book.add();
		else if(line == "SEARCH")
			Book.search();
		else if(line == "EXIT")
			break ;
		//display prompt;
		//getline from user
		//check if line matches ADD, EXIT or SEARCH and call the appropriate function
		//if exit then break the loop;
	}
}
