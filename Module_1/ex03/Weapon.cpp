/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:28:25 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 13:28:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string stype) {
	this->setType(stype);
	return ;
}

Weapon::~Weapon() {
	return ;
}

const std::string& Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string stype) {
	this->type = stype;
	return ;
}

