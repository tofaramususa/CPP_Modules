/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:04:59 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 19:26:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm 
{
	public:
		//Canonical Form
		ShrubberyCreationForm(const std::string& target); //constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other); //copy
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); //assignment
		virtual ~ShrubberyCreationForm();
		
		//executes the form's action
		void execute(Bureaucrat const & executor) const;
		private:
		ShrubberyCreationForm();
		class FileOpenException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
};

#endif