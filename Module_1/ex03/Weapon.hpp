/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:28:29 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 13:28:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private :
	std::string type;

	public :
	const std::string& getType();
	void setType(std::string stype);
	Weapon(std::string stype);
	~Weapon();
} ;

#endif