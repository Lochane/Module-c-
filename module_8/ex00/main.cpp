/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:55:27 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/11 15:05:05 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>

int main(void)
{
	// VECTOR //
	std::vector<int> v1;
	for (size_t i = 0; i <= 10; i += 1) {
		v1.push_back(i);
	}
	std::cout << "v1 = ";
	for (std::vector<int>::iterator i = v1.begin(), e = v1.end(); i != e; i += 1) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	try {
		easyfind(v1, 0);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		easyfind(v1, 20);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return EXIT_SUCCESS;
}