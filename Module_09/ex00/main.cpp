/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:30:15 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/16 16:52:37 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	// if (ac != 2){
	// 	std::cerr << "Programme need 1 argument" << std::endl;
	// 	return 1;
	// }
	(void)ac;
	(void)av;
	BitcoinData data;
	
	data.CreateMap("data.csv", data);
}