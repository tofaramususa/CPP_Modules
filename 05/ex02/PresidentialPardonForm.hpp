/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:16:54 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 19:24:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm 
{
	public:
		//Canonical Form
		PresidentialPardonForm(const std::string& target); //constructor
		PresidentialPardonForm(const PresidentialPardonForm &other); //copy
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other); //assignment
		virtual ~PresidentialPardonForm(); //why make it virtual
		
		//executes the form's action
		void execute(Bureaucrat const & executor) const;
		private:
		PresidentialPardonForm();
};

#endif