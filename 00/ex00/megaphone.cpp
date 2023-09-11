/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:01:53 by tofaramusus       #+#    #+#             */
/*   Updated: 2023/09/11 22:08:46 by tofaramusus      ###   ########.fr       */
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
				input[j] = toupper(input[j]);
			}
			std::cout << input;
		}
		std::cout << std::endl;
	}
}
