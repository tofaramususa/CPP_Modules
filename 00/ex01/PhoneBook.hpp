/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:47:52 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/11 13:54:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <ios>
#include <sstream>
#include <iostream>
#include  <iomanip>

#ifndef PHONEBOOK_H
#define PHONEBOOK_H


class PhoneBook
{
	private:
	Contact Contacts[8];
	int oldestContactIndex;
	int checkIndex(int index);
	void printTitles();
	void printContact(Contact contact, int index);
	std::string cutString(std::string text);

	public:
	PhoneBook();
	PhoneBook(std::string value);
	void add();
	void search();
	void displayPhoneBook();
	void setContacts(Contact Contacts);
} ;

std::string getInput(std::string Input);

#endif