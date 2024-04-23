/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:45:01 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 19:45:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){

	Zombie * Steve;
	
	Steve = newZombie("Steve");
	randomChump("Bob");
	Steve->announce();
	delete Steve;
	return 0;
}