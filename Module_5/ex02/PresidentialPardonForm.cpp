/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:40:17 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/26 18:32:12 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidantialPardon", 25, 5), _target("Default"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidantialPardon", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs), _target(rhs._target) {
	*this = rhs;	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	(void)rhs;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const{
	std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}