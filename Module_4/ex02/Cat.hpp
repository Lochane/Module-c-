/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titilamenace <titilamenace@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:37:08 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/17 16:38:13 by titilamenac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
// #include "Animal.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"

class Cat : public AAnimal {
	private :
		Brain *_brain;
	
	public :
		Cat();
		Cat(const Cat& rhs);
		~Cat();
		Cat &operator=(const Cat& rhs);
		
		void makeSound() const;
} ;

#endif