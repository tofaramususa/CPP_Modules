/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:49:51 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:39:24 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("Bro"), target("default"),signedStatus(false), signGrade(1), excGrade(1) 
{
}

AForm::AForm(const std::string& name, const std::string& target, int signGrade, int excGrade) : name(name), target(target), signedStatus(false), signGrade(signGrade), excGrade(excGrade) 
{
    if (signGrade < MAX || excGrade < MAX)
        throw GradeTooHighException();
    else if (signGrade > MIN || excGrade > MIN)
        throw GradeTooLowException();
	//add message to print functions std::cout
}

AForm::AForm(const AForm& other) :  name(other.name), signedStatus(other.signedStatus), signGrade(other.signGrade), excGrade(other.excGrade)
{
}

AForm& AForm::operator=(const AForm& other) 
{
    if (this != &other) 
	{
		this->signedStatus = other.signedStatus;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const 
{
    return name;
}

std::string AForm::getTarget() const 
{
    return target;
}

bool AForm::isSigned() const 
{
    return signedStatus;
}

int AForm::getSignGrade() const 
{
    return signGrade;
}

int AForm::getexcGrade() const 
{
    return excGrade;
}

void AForm::beSigned(Bureaucrat const & bureaucrat) 
{
    if (bureaucrat.getGrade() <= signGrade)
        signedStatus = true;
    else
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
    return "AForm grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() 
{
    return "Form is not Signed";
}


std::ostream& operator<<(std::ostream& os, const AForm& Aform) 
{
    os << "AForm: " << Aform.getName() << ", Sign Grade: " << Aform.getSignGrade() << ", Exec Grade: " << Aform.getexcGrade();
    if (Aform.isSigned()) 
	{
        os << ", Signed: Yes";
    } else 
	{
        os << ", Signed: No";
    }
    return os;
}

void AForm::isExecuted(const Bureaucrat& Bureaucrat) const
{
	if (this->signedStatus == false) {
		std::cout << Bureaucrat.getName() << " can't execute " << getName() << std::endl;
		throw AForm::FormNotSignedException();
	}
	if (Bureaucrat.getGrade() > this->excGrade) {
		std::cout << Bureaucrat.getName() << " can't execute " << getName() << std::endl;
		throw AForm::GradeTooLowException();
	}
}