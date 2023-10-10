/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:06:36 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/10 16:22:47 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
	void getFirstName();
	void getLastName();
	void getNickname();
	void getPhoneNumber();
	void getSecret();
	void setFirstName(std::string firstname);
	void setLastName(std::string lastname);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phonenumber);
	void setSecret(std::string secret);
} ;

#endif