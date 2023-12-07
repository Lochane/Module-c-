/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:44:16 by lsouquie          #+#    #+#             */
/*   Updated: 2023/11/30 19:56:44 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

PhoneBook::PhoneBook(){
	std::cout << "✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿" << std::endl;
	std::cout << "✿                                           ✿" << std::endl;
	std::cout << "✿\t\t ✿ Hello ✿                  ✿" << std::endl;
	std::cout << "✿   ✿ Welcome to your Awesome Phonebook ✿   ✿" << std::endl;
	std::cout << "✿                                           ✿" << std::endl;
	std::cout << "✿\t  ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿           ✿" << std::endl;
	std::cout << "✿                                           ✿" << std::endl;
	std::cout << "✿\t       ✿ HOW TO USE ✿               ✿" << std::endl;
	std::cout << "✿                                           ✿" << std::endl;
	std::cout << "✿     • ADD : Set a new contact             ✿" << std::endl;
	std::cout << "✿     • SEARCH : Search contact             ✿" << std::endl;
	std::cout << "✿     • EXIT : Quit and erase contact       ✿" << std::endl;
	std::cout << "✿                                           ✿" << std::endl;
	std::cout << "✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿" << std::endl<< std::endl;
	return;
}

PhoneBook::~PhoneBook(void){
	return;
}

// void PhoneBook::search_contact(PhoneBook book){
// 	return;
// }

void PhoneBook::add_contact(PhoneBook *book){
	
	if (book->index == 8)
		book->index = 1;
	std::cout << "✿ Please enter firstName ~>";
	std::cin >> book->input;
	book->_contacts[book->index].set_FirstName(book->input);
		std::cout << "✿ Please enter lastName ~>";
	std::cin >> book->input;
	book->_contacts[book->index].set_FirstName(book->input);
		std::cout << "✿ Please enter nickName ~>";
	std::cin >> book->input;
	book->_contacts[book->index].set_FirstName(book->input);
		std::cout << "✿ Please enter phoneNumber ~>";
	std::cin >> book->input;
	book->_contacts[book->index].set_FirstName(book->input);
		std::cout << "✿ Please enter darkestSecret ~>";
	std::cin >> book->input;
	book->_contacts[book->index].set_FirstName(book->input);
	book->index += 1;
	return;
}
