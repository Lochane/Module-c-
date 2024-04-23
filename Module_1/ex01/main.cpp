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

	int nb = 4;
	Zombie * horde = zombieHorde(nb, "Bob");
	for(int i = 0; i < nb; i++){
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}