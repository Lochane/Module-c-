/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:20:48 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/26 18:24:33 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public :
		Intern();
		Intern(const Intern& rhs);
		~Intern();
		Intern &operator=(const Intern& rhs);

		AForm* makeForm(std::string name, std::string target);
	
	class CantCreatForm : public std::exception{
		virtual const char* what() const throw();
	};
};


#endif