/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:15 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 19:41:18 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <stdlib.h>

#define MIN 150
#define MAX 1


class Bureaucrat 
{
	
	public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();

	
	private:
	class GradeTooHighException : public std::exception 
	{
		public:
			const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception 
	{
		public:
			const char *what() const throw();
	};
	
	const std::string name;
	int grade;
	
};

std::ostream& operator<<(std::ostream & os, Bureaucrat const & other);


#endif

