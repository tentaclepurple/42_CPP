/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:47:03 by codespace         #+#    #+#             */
/*   Updated: 2023/11/08 21:23:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static bool isValidName(const std::string& name)
{
    for (std::string::size_type i = 0; i < name.length(); ++i)
    {
        char c = name[i];
        if (!std::isalpha(c) && c != ' ')
            return (false);
    }
    return (true);
}

static bool isValidPhoneNumber(const std::string& phone) 
{
    for (std::string::size_type i = 0; i < phone.length(); ++i) 
    {
        char c = phone[i];
        if (!std::isdigit(c) && c != '+')
            return (false);
    }
    return (true);
}


static bool isOnlySpaces(const std::string& str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            return (false);
    }
    return (true);
}

int main() {
    Phonebook phonebook;

    std::string command;
    while (command != "EXIT") 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";

		std::getline(std::cin, command);

        if (std::cin.eof()) //if eof/ctrl+D terminate
			return (0);  
            
        else if (command == "ADD") 
        {
	        std::string first, last, nick, phone, secret;
            std::cout << "Enter first name: ";
             if (!std::getline(std::cin, first)) 
                return (0);
            std::cout << "Enter last name: ";
            if (!std::getline(std::cin, last))
                return (0);
            std::cout << "Enter nickname: ";
            if (!std::getline(std::cin, nick))
                return (0);
            std::cout << "Enter phone number: ";
            if (!std::getline(std::cin, phone))
                return (0);
            std::cout << "Enter darkest secret: ";
            if (!std::getline(std::cin, secret))
                return (0);
                
            // If empty input or only spaces. ask again
            if (first.empty() || isOnlySpaces(first) || last.empty() || isOnlySpaces(last) || nick.empty() || 
                isOnlySpaces(nick) || phone.empty() || isOnlySpaces(phone) || secret.empty() || isOnlySpaces(secret))
            {
                std::cout << "Invalid input. All fields must be non-empty." << std::endl;
                continue ;
            }
            
            if (!isValidName(first) || !isValidName(last))  //check if names only contain letters or ' '
            {
                std::cout << "Invalid first name or last name. They should contain only letters." << std::endl;
                continue ;
            }
            
            if (!isValidPhoneNumber(phone)) //check if phonenumbers only contain numbers or a '+' or ' '
            {
                std::cout << "Invalid phone number. It should contain only digits and/or '+'." << std::endl;
                continue ;
            }

            Contact newContact(first, last, nick, phone, secret);
            phonebook.addContact(newContact);
        } 
        else if (command == "SEARCH") 
        {
            if (phonebook.contact_count == 0)
            {
                std::cout << "Phonebook is empty." << std::endl;
                continue;
            }
            phonebook.displayContacts();
            int index;
            std::cout << "Enter the index of the contact to display: ";
            std::cin >> index;

            if (index >= 0 && index < phonebook.contact_count)
                phonebook.contacts[index].displayContactIndex(index); // Shows contact info
            else
                std::cout << "Invalid index." << std::endl;
            
            std::cin.ignore();
        }
    }
    return (0);
}