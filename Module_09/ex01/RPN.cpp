/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:35:47 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/22 15:33:02 by lsouquie         ###   ########.fr       */
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
		if (op_count != nb_count)
			throw WrongInput();
	}
}

void RPN::DoTheThing(){
	int res = _number.top();
	_number.pop();
	while (!_number.empty() && !_op.empty()){
		switch (_op.top()){
			case '-':{
				std::cout << "oaoaoaoaaaa" << std::endl;
				res -= _number.top();
				_op.pop();
				_number.pop();
					break ;
			}
			case '*':{
				std::cout << "ikikikikikikik" << std::endl;
				res *= _number.top();
				_op.pop();
				_number.pop();
					break ;
			}
			case '+': {
				std::cout << _op.top() << std::endl;
				res += _number.top();
				_op.pop();
				_number.pop();
					break ;
			}
			case '/':{
				std::cout << "prout" << std::endl;
				res /= _number.top();
				_op.pop();
				_number.pop();
					break ;
			}
		}
	}
	std::cout << res << std::endl;
}

RPN::RPN(std::string expre){
	if (expre.find_first_not_of("0123456789*/-+ \t\n\r\v") != std::string::npos)
		throw WrongInput();
	if (!ft_isdigit(expre[0] - '0') || !ft_isdigit(expre[2] - '0') || ft_isdigit(expre[expre.size() - 1] - '0'))
		throw WrongInput();
	CheckIntergrity(expre);
	int end_stack = expre.size() - 1;
	for (int i = end_stack; i >= 0; i--){
		if (expre[i] == ' ')
			i--;
		if (ft_isdigit(expre[i] - '0')){
			if ((expre[i - 1] == ' ' && expre[i + 1] == ' ') || i == 0)
				_number.push(expre[i] - '0');
			else
				throw WrongInput();
		}
		else if(!ft_isdigit(expre[i] - '0')){

			if ((expre[i - 1] == ' ' && expre[i + 1] == ' ') || i == end_stack)
				_op.push(expre[i]);
			else
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
