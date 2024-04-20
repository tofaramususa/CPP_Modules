/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:47:50 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/21 14:37:23 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook() : oldestContactIndex(0) {};

//add the contact to PhoneBook, it should take a Contact object as input and assign the values
void PhoneBook::add(void)
{
	Contact newContact(false);
	setContacts(newContact);
}

PhoneBook::PhoneBook(std::string value) : oldestContactIndex(0)
{
	std::string line;
	
	std::cout << value << std::endl;
	while(1)
	{
		std::cout << "ENTER ANY OF THE FOLLOWING [ADD] [SEARCH] [EXIT]: ";
		if(!std::getline (std::cin,line))
			break ;
		if(line == "ADD")
			add();
		else if(line == "SEARCH")
			search();
		else if(line == "EXIT")
			break ;
	}
}

//first thing is to display the contacts we currently have
void PhoneBook::search(void)
{
	int index;
	if(Contacts[0].isEmpty())
	{
		std::cout << "No Contacts to search for. Please ADD some." << std::endl;
		return ;
	}
	for(;;)
	{
		displayPhoneBook();
		std::stringstream value;
		value << getInput("Enter the index of the contact you want: ");
		int x = -1;
		value >> x;
		if(value.fail())
		{
			index = -1;
			std::cout << "The index you entered is not an integer between 0 and 7" << std::endl;
		}
		else
			index = checkIndex(x);
		if(index != -1)
		{
			Contacts[index].displayContact();
			break;			
		}
	}

}

std::string getInput(std::string Input)
{
	std::string line; 
	while(1)
	{
		std::cout << Input << " ";
		if(!std::getline(std::cin, line))
			std::exit(EXIT_SUCCESS);
		if(line != "")
			break ;
	}
	if(line == "EXIT")
		std::exit(EXIT_SUCCESS);
	return line;
}

void PhoneBook::setContacts(Contact Contact)
{
	Contacts[oldestContactIndex] = Contact;
	if (oldestContactIndex == 7)
	{
		oldestContactIndex = 0;
	}
	else
		oldestContactIndex += 1;
}

void PhoneBook::displayPhoneBook()
{
	//if no contacts then display no contacts and return false;
	PhoneBook::printTitles();
	for(int i = 0; i < 8; ++i)
	{
		if(!Contacts[i].isEmpty())
		{
			printContact(Contacts[i], i);
		}
	}
}

int PhoneBook::checkIndex(int index)
{
	if(index < 0 || index > 7)
	{
		std::cout << "The index you entered is not an integer between 0 and 7" << std::endl;
		return -1;
	}
	if(Contacts[index].isEmpty())
	{
		std::cout << "There is no Contact at the index you requested" << std::endl;
		return -1;
	}
	return index;
}

std::string PhoneBook::cutString(std::string text)
{
	if(text.length() > 10)
	{
		return text.substr(0, 9) + ".";
	}
	return text;
	
}

void PhoneBook::printTitles()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
}

void PhoneBook::printContact(Contact contact, int index)
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << cutString(contact.getFirstName()) << "|";
	std::cout << std::setw(10) << cutString(contact.getLastName()) << "|";
	std::cout << std::setw(10) << cutString(contact.getNickname()) << "|" << std::endl;
}
