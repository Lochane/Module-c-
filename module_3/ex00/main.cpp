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

#include "ClapTrap.hpp"

int main() {

	ClapTrap Bob("Bob");
	ClapTrap Carlos("Carlos");

	Bob.attack("Carlos");
	Carlos.attack("Bob");
	Bob.takeDamage(5);
	Bob.beRepaired(10);
	Bob.beRepaired(5);
	Bob.takeDamage(40);
	Bob.attack("Carlos");

	return 0;
}