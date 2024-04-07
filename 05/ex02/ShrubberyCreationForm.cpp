/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:04:57 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 20:41:49 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Form",target, 145, 137)  {}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form", "default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) 
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
    if (this != &other) 
	{
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	
}

void ShrubberyCreationForm::execute(Bureaucrat const  & executor) const 
{
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	try
	{
		this->isExecuted(executor);
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
	catch (std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}
	

}

//exception
const char* ShrubberyCreationForm::FileOpenException::what() const throw() 
{
    return "File could not Open";
}

