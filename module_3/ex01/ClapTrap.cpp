/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:16:11 by marvin            #+#    #+#             */
/*   Updated: 2024/01/13 19:16:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _energy_points(10), _attack_dmg(0), _hit_points(10){
	std::cout << "Claptrap " << this->_name << " enter the battle." << std::endl;
	return ;
}


ClapTrap::ClapTrap(std::string name) : _name(name), _energy_points(10), _attack_dmg(0), _hit_points(10) {
	std::cout << "Claptrap " << this->_name << " enter the battle." << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " has left the battle." << std::endl;
	return ;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energy_points == 0) {
		std::cout << "Claptrap " << this->_name << " has no energy point" << std::endl;
		return ;
	}
	else if (_hit_points == 0) {
		std::cout << "Claptrap " << this->_name << " can't attack cause he is dead" << std::endl;
		return ;
	}
	this->_energy_points -= 1;
	std::cout << "Claptrap " << this->_name << " attacks " << target << ",causing " << this->_attack_dmg << " points of damage" << std::endl;
	return ; 
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points <= amount) {
		_hit_points = 0;
		std::cout << "Claptrap " << this->_name << " is dead" << std::endl;
		return ;
	}
		this->_hit_points -= amount;
	std::cout << "Claptrap " << this->_name << " took " << amount << " damage." << std::endl;
	return ;
}


void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points == 0 || this->_hit_points <= 0) {
		std::cout << "Claptrap " << this->_name << " has no energy point" << std::endl;
		return ;
	}
	else if (amount + this->_hit_points > 10){
		std::cout << "Claptrap " << this->_name << " current health is " << this->_hit_points << ", you can't have more than 10 hit points." << std::endl;
		return ;
	}
	this->_energy_points -= 1;
	this->_hit_points += amount ;
	std::cout << "Claptrap " << this->_name << " repaired " << amount << ", of hit points, health are now " << this->_hit_points << std::endl;
	return ; 
}