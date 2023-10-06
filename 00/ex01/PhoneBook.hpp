/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:47:52 by tmususa           #+#    #+#             */
/*   Updated: 2023/09/15 15:17:36 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#ifndef PHONEBOOK_H
#define PHONEBOOK_H


class PhoneBook
{
	private:
	Contact Contacts[8];
	int	nbr_of_contacts;

} ;

#endif