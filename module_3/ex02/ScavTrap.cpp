/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:53:40 by marvin            #+#    #+#             */
/*   Updated: 2024/01/13 20:53:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO form cannonic otrhodox a faire

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;
	std::cout << "ScavTrap " << this->_name << " enter the battle" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std ::string name) : ClapTrap(name) {
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;
	std::cout << "ScavTrap " << this->_name << " enter the battle" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& src){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " has left the battle" << std::endl;
	return ;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl ;
	return ;
}

void ScavTrap::attack(const std::string& target){
	if (this->_energy_points == 0){
		std::cout << "ScavTrap " << this->_name << " has no energy points" << std::endl;
		return ;
	}
	else if (_hit_points == 0) {
		std::cout << "Claptrap " << this->_name << " can't attack cause he is dead" << std::endl;
		return ;
	}
	this->_energy_points -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ",causing " << this->_attack_dmg << " points of damage" << std::endl;
	return ;
}