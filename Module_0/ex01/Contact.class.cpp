/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:53:20 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/03 18:47:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void){
	return ;
}

Contact::~Contact(void){
	return ;
}

void Contact::display_contact(void){
	std::cout << std::endl << "              ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿              " << std::endl << std::endl;
	std::cout << "    • FirstName : " << this->_FirstName << std::endl ;
	std::cout << "    • LastName : " << this->_LastName << std::endl ;
	std::cout << "    • NickName : " << this->_NickName << std::endl ;
	std::cout << "    • PhoneNumber : " << this->_PhoneNumber << std::endl ;
	std::cout << "    • DarkestSecret : " << this->_DarkestSecret << std::endl ;
	std::cout << std::endl << "              ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿ ✿              " << std::endl << std::endl;
	return ;
}

void Contact::print_column(std::string output){

	std::string tmp = output;
	if (tmp.length() > 10)
	{
		tmp[9] = '.';
		for(int i = 10; tmp[i]; i++)
			tmp[i] = 0;
	}
	std::cout << "|" << std::setw(10) << tmp;
	return;
}

int Contact::init_column(int i){

	if (this->_FirstName.empty()){
		return 1;
	}
	std::cout << "|" << std::setw(10) << i;
	print_column(this->_FirstName);
	print_column(this->_LastName);
	print_column(this->_NickName);
	std::cout << "|" << std::endl;
	return 0;
}
void	Contact::set_FirstName(std::string input){
	this->_FirstName = input;
	return ;
}

void	Contact::set_LastName(std::string input){
	this->_LastName = input;
	return ;
}

void	Contact::set_NickName(std::string input){
	this->_NickName = input;
	return ;
}

void	Contact::set_PhoneNumber(std::string input){
	this->_PhoneNumber = input;
	return ;
}

void	Contact::set_DarkestSecret(std::string input){
	this->_DarkestSecret = input;
	return ;
}
