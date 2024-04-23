/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:20:14 by lsouquie          #+#    #+#             */
/*   Updated: 2024/01/20 16:19:06 by lsouquie         ###   ########.fr       */
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

bool Fixed::operator<(const Fixed& src) const {
	if (this->getRawBits() < src.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>(const Fixed& src) const {
	if (this->getRawBits() > src.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& src) const {
	if (this->getRawBits() <= src.getRawBits())
		return true;
	return false;
}


bool Fixed::operator>=(const Fixed& src) const {
	if (this->getRawBits() >= src.getRawBits())
		return true;
	return false;
}


bool Fixed::operator==(const Fixed& src) const {
	if (this->getRawBits() == src.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& src) const {
	if (this->getRawBits() != src.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed& src) const {
	return Fixed (this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed& src) const {
	return Fixed (this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed& src) const {
	return Fixed (this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed& src) const {
	return Fixed (this->toFloat() / src.toFloat());
}

Fixed Fixed::operator++(int a) {
	Fixed tmp;
	tmp._fixed_nb = this->_fixed_nb++;
	return (tmp);
}

Fixed Fixed::operator--(int a) {
	Fixed tmp;
	tmp._fixed_nb = this->_fixed_nb--;
	return (tmp);
}

Fixed& Fixed::operator++() {
	++this->_fixed_nb;
	return (*this);
}

Fixed& Fixed::operator--() {
	--this->_fixed_nb;
	return (*this);
}

Fixed Fixed::min(Fixed& lnb, Fixed& rnb) {
	if (lnb < rnb)
		return lnb;
	return rnb;
}

Fixed Fixed::min(const Fixed& lnb, const Fixed& rnb) {
	if (lnb < rnb)
		return lnb;
	return rnb;
}

Fixed Fixed::max(Fixed& lnb, Fixed& rnb) {
	if (lnb > rnb)
		return lnb;
	return rnb;
}

Fixed Fixed::max(const Fixed& lnb, const Fixed& rnb) {
	if (lnb > rnb)
		return lnb;
	return rnb;
}
