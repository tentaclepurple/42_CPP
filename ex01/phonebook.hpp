/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:30 by imontero          #+#    #+#             */
/*   Updated: 2023/11/07 15:41:04 by codespace        ###   ########.fr       */
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

	Contact() : 
	first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}
	
	Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret): 
	first_name(first), last_name(last), nickname(nick), phone_number(phone), darkest_secret(secret) {}

    // Getters
    std::string getFirstName() const { return first_name; }
    std::string getLastName() const { return last_name; }
    std::string getNickname() const { return nickname; }

        // Display contact details
    void displayContact(int index) const {
        std::cout << std::setw(10) << index << " | " << std::setw(10) << truncateString(first_name, 10) << " | "
                  << std::setw(10) << truncateString(last_name, 10) << " | " << std::setw(10) << truncateString(nickname, 10) << std::endl;
    }

};

class Phonebook
{

    


};



#endif