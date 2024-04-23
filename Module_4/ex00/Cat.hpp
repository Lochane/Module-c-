/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titilamenace <titilamenace@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:37:08 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/17 14:55:40 by titilamenac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	
	public :
		Cat();
		Cat(const Cat& rhs);
		~Cat();
		Cat &operator=(const Cat& rhs);
		
		void makeSound() const;
} ;

#endif