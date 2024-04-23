/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:01:53 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 19:01:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	return ;
}

Zombie::~Zombie(void){
	std::cout << this->_name << " is dead" << std::endl;
	return ;
}

void Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name){
	this->_name = name;
}