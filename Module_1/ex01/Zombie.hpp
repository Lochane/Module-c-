/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:01:47 by marvin            #+#    #+#             */
/*   Updated: 2024/01/03 19:01:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <new>

class Zombie {

private :

	std::string _name;

public :

	Zombie(void);
	~Zombie(void);

	void announce(void);
	void set_name(std::string name);
};

Zombie * zombieHorde(int N, std::string name);

#endif