/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:08:40 by marvin            #+#    #+#             */
/*   Updated: 2024/01/13 22:08:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hit_points = 100;
	_energy_points = 100;
	_attack_dmg = 30;
	std::cout << "FragTrap " << _name << " enter the battle." << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hit_points = 100;
	_energy_points = 100;
	_attack_dmg = 30;
	std::cout << "FragTrap " << _name << " enter the battle." << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& src){
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has left the battle." << std::endl;
	return ;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " is making hight fives." << std::endl;
	return ;
}

