/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:09:51 by lsouquie          #+#    #+#             */
/*   Updated: 2023/11/30 19:41:22 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class Contact {
	
private:

	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNumber;
	std::string _DarkestSecret;
	int 		_index;

public:

	Contact(void);
	~Contact(void);
	void	set_FirstName(std::string input);
	void	set_LastName(std::string input);
	void	set_NickName(std::string input);
	void	set_PhoneNumber(std::string input);
	void	set_DarkestSecret(std::string input);
};

#endif