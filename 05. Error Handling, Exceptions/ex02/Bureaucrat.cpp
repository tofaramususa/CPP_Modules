/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:10:12 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:39:37 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bro"), grade(MIN)
{
	
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < MAX)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	if (other.grade < MAX)
		throw Bureaucrat::GradeTooHighException();
	if (other.grade > MIN)
		throw Bureaucrat::GradeTooLowException();
	this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const 
{
	return this->grade;
}

void Bureaucrat::increment()
{
	this->grade--;
	if(this->grade < MAX)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement()
{
	this->grade++;
	if(this->grade > MIN)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const & other) 
{
  return os << other.getName() << ", bureaucrat grade " << other.getGrade();
}

void Bureaucrat::signForm(AForm& form) 
{
    try
	{
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << "" << std::endl;
    } catch (const AForm::GradeTooLowException& e) 
	{
        std::cout << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
	try 
	{
		form.isExecuted(*this);
		std::cout << this->getName() << " executed " << getName() << std::endl;
		form.execute(*this);
	} 
	catch (std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}
}
