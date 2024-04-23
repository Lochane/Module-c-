/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:30:51 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 11:30:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie * zombieHorde(int N, std::string name){

	if (N <= 0)
		return NULL;
	Zombie * horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return (horde);
}