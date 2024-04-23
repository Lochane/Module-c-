/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:20:14 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/20 16:06:11 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_nb(0){
	std::cout << "Default Constructor called." << std::endl;
	return ;
}

Fixed::Fixed(const float nb) {
	_fixed_nb = roundf(nb * (float)(1 << _bits));
	std::cout << "Float constructor called." << std::endl;
	return ;
}

Fixed::Fixed(int const nb) {
	_fixed_nb = (nb << _bits);
	std::cout << "Int constructor called." << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
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
	return this->_fixed_nb;
}

void Fixed::setRawBits(int const raw) {
	this->_fixed_nb = raw;
	return ;
}

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs) {
	lhs << rhs.toFloat();
	return lhs;
}

float Fixed::toFloat(void) const {
	return ((float)_fixed_nb /(float)(1 << _bits));
} 

int Fixed::toInt(void) const {
	return (_fixed_nb >> _bits);
}