/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:48:02 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/06 16:05:43 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **argv){
	
	if (ac != 2)
		return (0);
	try{
		std::string conv = argv[1];
		ScalarConverter::convert(conv);		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}