/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:30 by imontero          #+#    #+#             */
/*   Updated: 2023/11/07 22:28:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact 
{
    public:
        Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

        Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret): 
        first_name(first), last_name(last), nickname(nick), phone_number(phone), darkest_secret(secret) {}

        // Getters
        std::string getFirstName() const { return first_name; }
        std::string getLastName() const { return last_name; }
        std::string getNickname() const { return nickname; }

            // Display contact details
        void displayContact(int index) const 
        {
            std::cout << std::setw(10) << index << " | " << std::setw(10) << truncateString(first_name, 10) << " | "
                    << std::setw(10) << truncateString(last_name, 10) << " | " << std::setw(10) << truncateString(nickname, 10) << std::endl;
        }
    private:
    
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

        std::string truncateString(const std::string& str, int width) const 
        {
            if (str.length() <= width) 
                return str;
            return str.substr(0, width - 1) + ".";
        }
};



class Phonebook
{
    public:
        PhoneBook() : contact_count(0) {}

        bool addContact(const Contact& contact) 
        {
            if (contact_count < 8) 
            {
                contacts[contact_count] = contact;
                contacts_count++;
                return true;
            } 
            else 
            {
                std::cout << "Phonebook is full. Cannot add more contacts." << std::endl;
                return false;
            }
        }
        void displayContacts() const
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

    private:
        Contact contacts[8];
        int contact_count;
        int oldest_contact_index = 0;
};

#endif