/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:41:16 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 17:55:16 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("Default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs), _target(rhs._target) {
	*this = rhs;	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	(void)rhs;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const{
	std::cout << "*Makes some drilling noises*" << std::endl;
	srand(time(NULL));
	int	result = std::rand() % 2;
	if (result == 1)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " robotomy failed" << std::endl;
		
}