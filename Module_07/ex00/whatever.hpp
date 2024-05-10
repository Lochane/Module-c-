/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:22:48 by marvin            #+#    #+#             */
/*   Updated: 2024/05/09 10:22:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& a, T& b) {
	T swap = a;
	a = b;
	b = swap;
}

template <typename T>
T min(const T& a, const T& b) {
	if (a == b || a > b)
		return b;
	else 
		return a;
		
}

template <typename T>
T max(const T& a, const T& b) {
	if (a == b || a < b)
		return b;
	else 
		return a;
}

#endif