/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titilamenace <titilamenace@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:32:47 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/17 14:58:01 by titilamenac      ###   ########.fr       */
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