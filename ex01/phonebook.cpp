/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:19:48 by codespace         #+#    #+#             */
/*   Updated: 2023/11/08 10:38:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(): contact_count(0), oldest_contact_index(0) {}

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
    std::cout << std::setw(10) << std::right << "Index" << " | " 
          << std::setw(10) << std::right << "First Name" << " | " 
          << std::setw(10) << std::right << "Last Name" << " | " 
          << std::setw(10) << std::right << "Nickname" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for (int i = 0; i < contact_count; ++i)
        contacts[i].displayContact(i);
}