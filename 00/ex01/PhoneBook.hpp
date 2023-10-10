/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:47:52 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/10 15:44:12 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <sstream>
#include <iostream>

#ifndef PHONEBOOK_H
#define PHONEBOOK_H


class PhoneBook
{
	private:
	Contact Contacts[8];
	int oldestContactIndex;
	int checkIndex(int index);

	public:
	PhoneBook();
	void add();
	void search();
	bool displayPhoneBook();
	void setContacts(Contact Contacts);
} ;

std::string getPrompt(std::string prompt);

#endif