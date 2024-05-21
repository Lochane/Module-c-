/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:35:47 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/21 18:24:52 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	RPN::ft_isdigit(int c){
	if ((c >= 0  && c <= 9))
		return true;
	return false;
}

void RPN::CheckIntergrity(std::string expre){
	int i = 1;
	while (expre[i]){
		int nb_count = 0;
		int op_count = 0;
		while (expre[i] && (ft_isdigit(expre[i] - '0') || expre[i] == ' ')){
			if (expre[i] != ' ')
				nb_count++;
			i++;	 
		}
		while (expre[i] && (!ft_isdigit(expre[i] - '0') || expre[i] == ' ')){
			if (expre[i] != ' ')
				op_count++;
			i++;
		}
		if (op_count != nb_count){
			throw WrongInput();
		}
	}
}


RPN::RPN(std::string expre){
	if (expre.find_first_not_of("0123456789*/-+ \t\r\n\v") != std::string::npos)
		throw WrongInput();
	if (!ft_isdigit(expre[0] - '0') || !ft_isdigit(expre[2] - '0') || ft_isdigit(expre[expre.size() - 1] - '0'))
		throw WrongInput();
	CheckIntergrity(expre);
	int end_stack = expre.size() - 1;
	for (int i = end_stack; i >= 0; i--){
		if (expre[i] == ' ')
			i--;
		if (ft_isdigit(expre[i] - '0') == true && ((expre[i - 1] == ' ') || i == 0)){
			_number.push(expre[i] - '0');
		}
		else if(!ft_isdigit(expre[i] - '0') && ((expre[i - 1] != ' ') || (expre[i + 1] != ' '))){
				
			if (i != end_stack)
				throw WrongInput();
			}
	}
}

// RPN::RPN(const RPN& rhs){
	
// }

RPN::~RPN(){
	
}

// RPN& RPN::operator=(const RPN& rhs){
	
// }

const char *RPN::WrongInput::what() const throw(){
	return "Wrong input";
}
