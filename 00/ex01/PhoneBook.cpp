/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:47:50 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/10 16:23:54 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook() : oldestContactIndex(0) {};

//add the contact to PhoneBook, it should take a Contact object as input and assign the values
void PhoneBook::add(void)
{
	Contact newContact(true);
	setContacts(newContact);
}

//first thing is to display the contacts we currently have
void PhoneBook::search(void)
{
	int index;
	while(displayPhoneBook())
	{
		std::stringstream value;
		value << getPrompt("Enter the index of the contact you want: ");
		int x = -1;
		value >> x;
		index = checkIndex(x);
		if(index)
		{
			Contacts[index].displayContact();
			break;			
		}
	}

}

std::string getPrompt(std::string prompt)
{
	std::string line; 
	while(1)
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, line);
		if(line != "")
			break ;
	}
	if(line == "EXIT")
		exit(0);
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

bool PhoneBook::displayPhoneBook()
{
	//if no contacts then display no contacts and return false;

	//else display phonebook
}

int PhoneBook::checkIndex(int index)
{
	if(index < 0 || index > 7)
	{
		std::cout << "The index you entered is not between 0 and 7" << std::endl;
		return NULL;
	}
	if(Contacts[index].isEmpty())
	{
		std::cout << "The index you entered returns an Empty Contact" << std::endl;
		return NULL;
	}
	return index;
}
