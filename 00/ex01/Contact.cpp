/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:47:42 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/10 16:37:46 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact() : Empty(true) {}

Contact::Contact(bool Empty) : Empty(Empty)
{
	Contact::setFirstName(getPrompt("Enter First Name: "));
	Contact::setLastName(getPrompt("Enter Last Name: "));
	Contact::setNickname(getPrompt("Enter Nickname: "));
	Contact::setPhoneNumber(getPrompt("Enter Phone Number"));
	Contact::setSecret(getPrompt("Enter Darkest Secret: "));
}

bool Contact::isEmpty()
{
	return Empty;
}

