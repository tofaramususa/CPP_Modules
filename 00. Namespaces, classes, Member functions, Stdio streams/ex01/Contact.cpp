/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tofaramususa <tofaramususa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:47:42 by tmususa           #+#    #+#             */
/*   Updated: 2024/03/25 22:33:53 by tofaramusus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact() : Empty(true)
{
}

Contact::Contact(bool Empty) : Empty(Empty)
{
	Contact::setFirstName(getInput("Enter First Name: "));
	Contact::setLastName(getInput("Enter Last Name: "));
	Contact::setNickname(getInput("Enter Nickname: "));
	Contact::setPhoneNumber(getInput("Enter Phone Number: "));
	Contact::setSecret(getInput("Enter Darkest Secret: "));
}

bool Contact::isEmpty()
{
	return (Empty);
}

void Contact::displayContact()
{
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << "Secret: " << getSecret() << std::endl;
}

std::string Contact::getFirstName()
{
	return (firstname);
}
std::string Contact::getLastName()
{
	return (lastname);
}
std::string Contact::getNickname()
{
	return (nickname);
}
std::string Contact::getPhoneNumber()
{
	return (phoneNumber);
}
std::string Contact::getSecret()
{
	return (secret);
}
void Contact::setFirstName(std::string value)
{
	firstname = value;
}

void Contact::setLastName(std::string value)
{
	lastname = value;
}
void Contact::setNickname(std::string value)
{
	nickname = value;
}
void Contact::setPhoneNumber(std::string value)
{
	phoneNumber = value;
}
void Contact::setSecret(std::string value)
{
	secret = value;
}
