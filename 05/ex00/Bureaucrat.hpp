/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:15 by marvin            #+#    #+#             */
/*   Updated: 2024/04/06 21:15:33 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <stdlib.h>

//Define colors below here
//green for constructor
//red for destructor
//blue for other functions

#define MIN 150
#define MAX 1


class Bureaucrat 
{
	
	public:
	//Canonical Form
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
			const char *what() const throw(); //what is this part again?
	};
	
	const std::string name;
	int grade;
	
};

std::ostream& operator<<(std::ostream & os, Bureaucrat const & other);


#endif

