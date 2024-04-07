/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:13:11 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 21:07:40 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

class Intern 
{
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();
		Intern& operator=(const Intern& other);
		AForm* makeForm(std::string name, std::string target);

		class FormNotCreatedException: public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
};

#endif