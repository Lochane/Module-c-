/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:27:15 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/11 15:04:36 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>


class NoFound: public std::exception {
	public:
		const char* what() const throw(){
			return "No match found";
		}
};

template<typename T>
bool easyfind(T cont, int n){
		typename T::iterator res = std::find(cont.begin(), cont.end(), n);
		if (res == cont.end())
			throw NoFound();
		else
			return true;
		return false;
}


#endif