/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:44:01 by marvin            #+#    #+#             */
/*   Updated: 2024/01/13 19:44:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {

	ScavTrap joel("Joel");
	ScavTrap ellie("Ellie");
	ScavTrap zombie("Zombie");

	joel.attack("Zombie");
	ellie.attack("Zombie");
	zombie.takeDamage(50);
	zombie.attack("Joel");
	joel.takeDamage(20);
	joel.beRepaired(10);
	ellie.attack("Zombie");
	joel.attack("Zombie");
	zombie.takeDamage(50);
	ellie.guardGate();
	return 0;
}