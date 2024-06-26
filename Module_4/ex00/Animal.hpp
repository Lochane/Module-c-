/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:47 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 18:08:48 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
	
	protected : 
		std::string _type;
	
	public :
		Animal();
		Animal(const std::string type);
		Animal(const Animal& rhs);
		virtual ~Animal();
		Animal &operator=(const Animal& rhs);
		
		virtual void makeSound() const;
		const std::string& getType() const;
} ;

#endif