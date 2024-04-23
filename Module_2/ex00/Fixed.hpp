/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titilamenace <titilamenace@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:09:33 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/16 14:56:45 by titilamenac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	private : 
		int _fixed_nb;
		static int const _bits = 8;
	
	public :
		Fixed();
		Fixed(const Fixed& src);
		~Fixed();
		Fixed &operator=(const Fixed& src);
		int getRawBits(void)const;
		void setRawBits(int const raw);
		
} ;

#endif