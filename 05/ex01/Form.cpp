/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:49:51 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:08:07 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("Bro"), signedStatus(false), signGrade(1), excGrade(1) 
{
}

Form::Form(const std::string& name, int signGrade, int excGrade) : name(name), signedStatus(false), signGrade(signGrade), excGrade(excGrade) 
{
    if (signGrade < MAX || excGrade < MAX)
        throw GradeTooHighException();
    else if (signGrade > MIN || excGrade > MIN)
        throw GradeTooLowException();
	//add message to print functions std::cout
}

Form::Form(const Form& other) :  name(other.name), signedStatus(other.signedStatus), signGrade(other.signGrade), excGrade(other.excGrade)
{
}

Form& Form::operator=(const Form& other) 
{
    if (this != &other) 
	{
		this->signedStatus = other.signedStatus;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const 
{
    return name;
}

bool Form::isSigned() const 
{
    return signedStatus;
}

int Form::getSignGrade() const 
{
    return signGrade;
}

int Form::getexcGrade() const 
{
    return excGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() <= signGrade)
        signedStatus = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Form grade is too low";
}


std::ostream& operator<<(std::ostream& os, const Form& form) 
{
    os << "Form: " << form.getName() << ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: " << form.getexcGrade();
    if (form.isSigned()) 
	{
        os << ", Signed: Yes";
    } else 
	{
        os << ", Signed: No";
    }
    return os;
}
