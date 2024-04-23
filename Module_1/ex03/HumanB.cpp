/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:28:06 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 13:28:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	this->weapon = NULL;
	return ;
}

HumanB::~HumanB() {
	return ;
}

void HumanB::setWeapon(Weapon& sweapon){
	this->weapon = &sweapon;
}

void HumanB::attack() {
	if (weapon != NULL && this->weapon->getType() != "")
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " don't have weapon" << std::endl;
}
