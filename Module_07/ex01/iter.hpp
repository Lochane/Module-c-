/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:54:40 by marvin            #+#    #+#             */
/*   Updated: 2024/05/09 10:54:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <iomanip>
#include <string>

template<typename T, typename F>
void iter(T* a, size_t lenght, F func){
	for(size_t i = 0; i < lenght; i++)
		func(a[i]);
}

template<typename T>
void t_print(const T& e){
	std::cout << e << std::endl;
}

#endif