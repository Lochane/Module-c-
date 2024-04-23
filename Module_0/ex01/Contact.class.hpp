/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:09:51 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/03 18:14:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
	
private:

	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNumber;
	std::string _DarkestSecret;

public:

	Contact(void);
	~Contact(void);
	void	set_FirstName(std::string input);
	void	set_LastName(std::string input);
	void	set_NickName(std::string input);
	void	set_PhoneNumber(std::string input);
	void	set_DarkestSecret(std::string input);
	int 	init_column(int i);
	void 	print_column(std::string output);
	void	display_contact(void);

};

#endif