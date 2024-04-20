/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:30:34 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 19:49:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
# include <ctime>

class RobotomyRequestForm : public AForm 
{
	public:
		//Canonical Form
		RobotomyRequestForm(const std::string& target); //constructor
		RobotomyRequestForm(const RobotomyRequestForm &other); //copy
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other); //assignment
		virtual ~RobotomyRequestForm(); //why make it virtual
		
		//executes the form's action
		void execute(Bureaucrat const & executor) const;
		private:
		RobotomyRequestForm();
};

#endif