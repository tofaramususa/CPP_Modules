/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:44:42 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 19:55:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Bureaucrat.hpp"

#define MIN 150
#define MAX 1

class Bureaucrat; // Forward declaration

class AForm 
{
	public:
		// Canonical AForm
		AForm();
		AForm(const std::string& name, const std::string& target, int signGrade, int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		
		virtual ~AForm();
		virtual void execute(Bureaucrat const & executor) const = 0;

		//getters
		std::string getName() const;
		std::string getTarget() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void isExecuted(const Bureaucrat& bureaucrat) const;
		
		void beSigned(Bureaucrat const & bureaucrat);

		//exceptions
		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception 
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string name;
		const std::string target;
		bool signedStatus;
		const int signGrade;
		const int execGrade;
		class GradeTooHighException : public std::exception 
		{
			public:
				const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif
