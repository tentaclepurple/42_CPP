/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:19:48 by codespace         #+#    #+#             */
/*   Updated: 2023/11/07 23:46:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(): contact_count(0), oldest_contact_index(0) {}

bool Phonebook::addContact(const Contact& contact)
{
    if (contact_count < 8) 
    {
        contacts[contact_count] = contact;
        contact_count++;
        return (true);
    } 
    else 
    {
        std::cout << "Phonebook is full. Cannot add more contacts." << std::endl;
        return (false);
    }
}

void    Phonebook::displayContacts() const
{
    if (contact_count == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << "Index      | First Name | Last Name  | Nickname" << std::endl;
    for (int i = 0; i < contact_count; ++i)
        contacts[i].displayContact(i);
}