/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:33:49 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/15 15:23:38 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONBOOK_CLASS_H
# define PHONBOOK_CLASS_H

# include "Contact.class.hpp"

class PhoneBook {

private:
	
	Contact _contacts[8];

public:
	
	std::string input;
	int index;
	int max_contact;

	PhoneBook(void);
	~PhoneBook(void);
	
	int  verify_digit(std::string str);
	void add_contact(PhoneBook *book);
	void search_contact(PhoneBook *book);	
};

#endif
