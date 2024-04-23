/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:27:58 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 13:27:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {

	private :
		std::string name;
		Weapon* weapon;

	public :
		HumanB(std::string sname);
		~HumanB();
		void attack();
		void setWeapon(Weapon& sweapon);
} ;

#endif