/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:04:57 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 20:06:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm.cpp
#include "ShrubberyCreationForm.hpp"

//name constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Form",target, 145, 137) 
{
	//print
}

//default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form", "default", 145, 137)
{
	//print
}

//copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) 
{
	*this = other;
}

//assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) 
	{
        AForm::operator=(other);
    }
    return *this;
}

//destructor
ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	
}

void ShrubberyCreationForm::execute(Bureaucrat const  & executor) const 
{
	if (!isSigned()) 
	{
		throw FormNotSignedException();
	}
	
	else if (this->getSignGrade() < executor.getGrade()) 
	{
		std::cout << "Form  cannot be executed because the rank is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else 
	{
		std::string filename = this->getTarget() + "_shrubbery";
		std::ofstream outfile(filename.c_str());
			if (outfile.is_open()) 
			{
				outfile << "       /\\      " << std::endl;
				outfile << "      /\\*\\    " << std::endl;
				outfile << "     /\\O\\*\\    " << std::endl;
				outfile << "    /\\O\\/\\/\\   " << std::endl;
				outfile << "   /\\*\\/\\*\\/\\  " << std::endl;
				outfile << "  /\\O\\/\\/*/\\/\\ " << std::endl;
				outfile << " /\\*\\/\\*\\/\\/\\/\\" << std::endl;
				outfile << "/\\O\\/\\/*/\\/O/\\/\\ " << std::endl;
				outfile << "      |||||      " << std::endl;
				outfile << "      |||||      " << std::endl;
				outfile << "      |||||      " << std::endl;
				outfile.close();
				std::cout << "Shrubbery creation form executed successfully by " << executor.getName() << std::endl;
			} 
			else 
			{
				throw FileOpenException();
			}
	}
}

//exception
const char* ShrubberyCreationForm::FileOpenException::what() const throw() 
{
    return "File could not Open";
}

