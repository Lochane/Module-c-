/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:20:43 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/01 14:02:19 by lsouquie         ###   ########.fr       */
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

AForm* Intern::makePresidentialPardon(std::string target){
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequest(std::string target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShruberryCreation(std::string target){
	return new ShrubberryCreationForm(target);
}

AForm* Intern::Intern::makeForm(std::string name, std::string target) {
	std::string FormName[] = {"robotomy request", "presidential pardon", "shrubberry creation"};
	
AForm* (Intern::*FormRef[])(std::string) = {&Intern::makeRobotomyRequest, &Intern::makePresidentialPardon, &Intern::makeShruberryCreation};
	
	for(int i = 0; i < 3; i++){
		if (name == FormName[i]){
			std::cout << "Intern creates " << name << std::endl;
			 return (this->*FormRef[i])(target);
		}
	}
	throw CantCreatForm();
	return NULL;
}

const char* Intern::CantCreatForm::what() const throw() {
	return "Intern could not create form";
}