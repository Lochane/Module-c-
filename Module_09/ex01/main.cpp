/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:42:23 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/21 11:41:05 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	try {		
		RPN rpn(av[1]);
	}
	catch(std::exception &e){
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}