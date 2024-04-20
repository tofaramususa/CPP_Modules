/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:44:42 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:35:21 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <stdlib.h>
# include <string>

# define MIN 150
# define MAX 1

class Bureaucrat; // Forward declaration

class AForm
{
  public:
	AForm();
	AForm(const std::string &name, const std::string &target, int signGrade,
		int excGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	virtual ~AForm();
	virtual void execute(Bureaucrat const &executor) const = 0;

	std::string getName() const;
	std::string getTarget() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getexcGrade() const;
	void isExecuted(const Bureaucrat &bureaucrat) const;

	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
		const char *what() const throw();
	};

  private:
	const std::string name;
	const std::string target;
	bool signedStatus;
	const int signGrade;
	const int excGrade;
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);

#endif
