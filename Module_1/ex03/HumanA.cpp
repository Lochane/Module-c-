/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:28:10 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 13:28:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string sname, Weapon& sweapon) : name(sname), weapon(sweapon){
	return ;
}

HumanA::~HumanA() {
	return ;
}

void HumanA::attack() {
		std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
