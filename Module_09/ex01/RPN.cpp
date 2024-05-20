/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:35:47 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/20 20:44:50 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<char> CreateStack(std::string expre){
	std::stack<char> stack;

	(void)expre;
	stack.push('c');
	std::cout << stack.top() << std::endl;
	return stack;
}