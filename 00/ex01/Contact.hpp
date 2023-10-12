/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:06:36 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/11 13:14:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>

#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
	private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;
	bool Empty;

	public:
	Contact();
	Contact(bool Empty);
	bool isEmpty();
	void displayContact();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getSecret();
	void setFirstName(std::string value);
	void setLastName(std::string value);
	void setNickname(std::string value);
	void setPhoneNumber(std::string value);
	void setSecret(std::string value);
} ;

#endif