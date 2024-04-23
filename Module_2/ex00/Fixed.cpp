/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:20:14 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/20 16:03:12 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_nb(0){
	std::cout << "Default Constructor called." << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called." << std::endl;
	this->setRawBits(src.getRawBits());
	return ;
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &src)
		_fixed_nb = src.getRawBits();
	return *this;
}

Fixed::~Fixed () {
	std::cout << "Destructor called." << std::endl;
	return ;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_nb;
}

void Fixed::setRawBits(int const raw) {
	this->_fixed_nb = raw;
	return ;
}