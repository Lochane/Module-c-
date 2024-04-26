/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:20:43 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/26 18:42:18 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& rhs) {
	*this = rhs;
}

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string FormName[] = {"robotomy request", "presidential pardon", "shrubberry creation"};
	
	AForm* FormRef[] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberryCreationForm(target)};
	// AForm* FormToReturn = NULL;
	
	for(int i = 0; i < 3; i++){
		if (name == FormName[i]){
			std::cout << "Intern creates " << name << std::endl;
			// FormToReturn = FormRef[i];
			return FormRef[i];
		}
		// else 
		// 	delete FormRef[i];
	}
	throw CantCreatForm();
	return NULL;
}

const char* Intern::CantCreatForm::what() const throw() {
	return "Intern could not create form";
}