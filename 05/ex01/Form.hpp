/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:44:42 by marvin            #+#    #+#             */
/*   Updated: 2024/04/06 21:18:58 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdlib.h>
# include <string>

# define MIN 150
# define MAX 1

class Bureaucrat; // Forward declaration

class Form
{
	public:
		// Canonical Form
		Form();
		Form(const std::string &name, int signGrade, int execGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		std::string getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);
		class GradeTooLowException : public std::exception
		{
			public:
			const char *what() const throw();
		};

	private:
		const std::string name;
		bool signedStatus;
		const int signGrade;
		const int execGrade;
		class GradeTooHighException : public std::exception
		{
			public:
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
