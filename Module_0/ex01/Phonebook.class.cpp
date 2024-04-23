/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:44:16 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/15 15:38:12 by lsouquie         ###   ########.fr       */
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

int PhoneBook::verify_digit(std::string str){
	for (int i = 0; str[i]; i++){
		if (!isdigit(str[i]))
			return 1;
	}
	return 0;
}

void PhoneBook::search_contact(PhoneBook *book){
	
	int i = 0;
	while (i <= max_contact && i < 8)
	{
		if(book->_contacts[i].init_column(i + 1) == 1)
		{
			if (i == 0)
			{
				std::cout << "    PhoneBook empty. Please 'ADD' contacts.\n";
				return ;
			}
		}
		i++;
	}
	while (true)
	{
		std::cout << "  • Enter contact index ~> ";
		std::getline(std::cin, book->input);
		if (std::cin.eof())
			return ;
		if (book->input.empty()){
			std::cout << "Index can't be empty. Please enter again.\n";
		}
		else {
			if (verify_digit(book->input) == 0){
				int a = std::stoi(book->input, nullptr, 10);
				if (a < 1 && a > 8)
					std::cout << "Please enter only digit between 1 and 8.\n";
				else {
					book->_contacts[a - 1].display_contact();
					break ;
				}	
			}
			else
				std::cout << "Please enter only digit between 1 and 8.\n";
		}
	}
	return ;
}


void PhoneBook::add_contact(PhoneBook *book) {
    if (book->index == 7)
        book->index = 0;
	book->max_contact++;
	while (true|| std::cin.eof())
	{
		std::cout << "  • Enter firstName ~> ";
		std::getline(std::cin, book->input);
		if (std::cin.eof())
			return ;
		if (book->input.empty()) {
			std::cout << "First name cannot be empty. Please enter again.\n";
		}
		else
			break ;
	}
	book->_contacts[book->index].set_FirstName(book->input);
	while (true || std::cin.eof()){
		std::cout << "  • Enter lastName ~> ";
		std::getline(std::cin, book->input);
		if (std::cin.eof())
			return ;
		if (book->input.empty()) {
			std::cout << "Last name cannot be empty. Please enter again.\n";
		}
		else
			break ;
	}
	book->_contacts[book->index].set_LastName(book->input);
	while (true || std::cin.eof()){
		std::cout << "  • Enter nickName ~> ";
		std::getline(std::cin, book->input);
		if (std::cin.eof())
			return ;
		if (book->input.empty()) {
			std::cout << "Nickname cannot be empty. Please enter again.\n";
		}
		else
			break ;
	}
	book->_contacts[book->index].set_NickName(book->input);
	while(true || std::cin.eof()){
		std::cout << "  • Enter phoneNumber ~> ";
		std::getline(std::cin, book->input);
		if (std::cin.eof())
			return ;
		if (book->input.empty()) {
			std::cout << "Phone number cannot be empty. Please enter again.\n";
		}
		else if (verify_digit(book->input) == 0)
			std::cout << "Please Enter only digit." << std::endl;
		else
			break ;
	}
	book->_contacts[book->index].set_PhoneNumber(book->input);
	while(true || std::cin.eof()){
		std::cout << "  • Enter darkestSecret ~> ";
		std::getline(std::cin, book->input);
		if (std::cin.eof())
			return ;
		if (book->input.empty()) {
			std::cout << "Darkest secret cannot be empty. Please enter again.\n";	
		}
		else
			break ;
	}
	book->_contacts[book->index].set_DarkestSecret(book->input);
    book->index += 1;
    return;
}

