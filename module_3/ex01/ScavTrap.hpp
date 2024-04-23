/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:03:17 by marvin            #+#    #+#             */
/*   Updated: 2024/01/13 20:03:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

		public :
			ScavTrap();
			ScavTrap(const ScavTrap& other);
			ScavTrap(std::string name);
			ScavTrap& operator=(const ScavTrap& other);
			~ScavTrap();

			void guardGate();
			void attack(const std::string& target);
} ;

#endif