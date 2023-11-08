/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:47:03 by codespace         #+#    #+#             */
/*   Updated: 2023/11/08 00:09:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static bool isValidName(const std::string& name) {
    for (char c : name) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}

static bool isValidPhoneNumber(const std::string& phone) {
    for (char c : phone) {
        if (!std::isdigit(c) && c != '+') {
            return false;
        }
    }
    return true;
}

int main() {
    PhoneBook phoneBook;

    while (true) 
    {
        std::string command;
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD") 
        {
            std::string first, last, nick, phone, secret;
            std::cout << "Enter first name: ";
            std::cin >> first;
            std::cout << "Enter last name: ";
            std::cin >> last;
            std::cout << "Enter nickname: ";
            std::cin >> nick;
            std::cout << "Enter phone number: ";
            std::cin >> phone;
            std::cout << "Enter darkest secret: ";
            std::cin >> secret;

            // If empty input, ask again
            if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty())
            {
                std::cout << "Invalid input. All fields must be non-empty." << std::endl;
                continue ;
            }
            if (!isValidPhoneNumber(phone))
            {
                std::cout << "Invalid phone number. It should contain only digits and/or '+'." << std::endl;
                continue ;
            }
            if (!isValidName(first) || !isValidName(last))
            {
                std::cout << "Invalid first name or last name. They should contain only letters." << std::endl;
                continue ;
            }

            Contact newContact(first, last, nick, phone, secret);
            phoneBook.addContact(newContact);
        } 
        else if (command == "SEARCH") 
        {
            phoneBook.displayContacts();
            int index;
            std::cout << "Enter the index of the contact to display: ";
            std::cin >> index;

            if (index >= 0 && index < phoneBook.contact_count)
                phoneBook.contacts[index].displayContact(index); // Muestra otros detalles del contacto si es necesario
            else
                std::cout << "Invalid index." << std::endl;
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
    }

    return (0);
}