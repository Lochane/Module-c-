/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:33:49 by lsouquie          #+#    #+#             */
/*   Updated: 2023/11/30 19:53:31 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONBOOK_CLASS_H
# define PHONBOOK_CLASS_H

# include "Contact.class.hpp"

class PhoneBook {

private:
	
	Contact _contacts[8];
	void	_read_input(void);

public:
	
	std::string input;
	int index;

	PhoneBook(void);
	~PhoneBook(void);
	
	void add_contact(PhoneBook *book);
	int	find_index(PhoneBook book);
	// void search_contact(Phonebook book);
};

#endif
