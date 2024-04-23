/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:05:37 by marvin            #+#    #+#             */
/*   Updated: 2024/01/13 19:05:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	protected :

	std::string _name;
	unsigned int _energy_points;
	unsigned int _attack_dmg;
	unsigned int _hit_points;

	public :

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap(std::string name);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();
} ;

#endif