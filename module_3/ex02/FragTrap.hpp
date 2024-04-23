/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:09:05 by marvin            #+#    #+#             */
/*   Updated: 2024/01/13 22:09:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public :

	FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap(std::string name);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	void highFivesGuys(void);

};

#endif
