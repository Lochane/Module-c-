/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:46:11 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 12:46:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){

	std::string brain = "'HI THIS IS BRAIN'";
	std::string *stringPTR = &brain;
	std::string& stringREF = brain;
	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}