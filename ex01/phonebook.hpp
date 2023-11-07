/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:30 by imontero          #+#    #+#             */
/*   Updated: 2023/11/07 23:43:46 by codespace        ###   ########.fr       */
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
		//default constructors
        Contact();

        Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret); 

        // Getters
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
		std::string getPhoneNumber() const;
	    std::string getDarkestSecret() const;

        // Display contact details
        void displayContact(int index) const;
       
    private:
    
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

        std::string truncateString(const std::string& str, int width) const;

};

class Phonebook
{
    public:
		PhoneBook();

        bool addContact(const Contact& contact);
        
        void displayContacts() const;
        

    private:
        Contact contacts[8];
        int contact_count;
        int oldest_contact_index = 0;
};

#endif