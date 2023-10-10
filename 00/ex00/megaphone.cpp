/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:01:53 by tofaramusus       #+#    #+#             */
/*   Updated: 2023/10/10 17:55:53 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **argv)
{
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for(int i = 1; i < ac; i++)
		{
			std::string input(argv[i]);
			for(std::string::size_type j = 0; j < input.length(); j++)
			{
				input[j] = std::toupper(input[j]);
			}
			std::cout << input;
		}
		std::cout << " " << std::endl;
		std::cout << std::endl;
	}
}
