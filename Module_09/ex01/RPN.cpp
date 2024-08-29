/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:35:47 by lsouquie          #+#    #+#             */
/*   Updated: 2024/08/29 18:52:53 by lsouquie         ###   ########.fr       */
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

RPN::RPN(std::string expre){
	if (expre.find_first_not_of("0123456789*/-+ \t\n\r\v") != std::string::npos)
		throw WrongInput();
	if (!ft_isdigit(expre[0] - '0') || !ft_isdigit(expre[2] - '0') || ft_isdigit(expre[expre.size() - 1] - '0'))
		throw WrongInput();
	CheckIntergrity(expre);
	for (size_t i = 0; expre[i]; i++){
		if (expre[i] == ' ')
			i++;
		if (ft_isdigit(expre[i] - '0')){
			if ((expre[i - 1] == ' ' && expre[i + 1] == ' ') || i == 0)
				_number.push(expre[i] - '0');
			else
				throw WrongInput();
		}
		else if(!ft_isdigit(expre[i] - '0')){

			if ((expre[i - 1] == ' ') && (expre[i + 1] == ' ' || i == expre.size() - 1)){
				int b = _number.top(); _number.pop();
				int a = _number.top(); _number.pop();
				int res = DoTheThing(a, b, expre[i]);
				_number.push(res);
			}
			else
				throw WrongInput();
		}
	}
	std::cout << _number.top() << std::endl;
}

int RPN::DoTheThing(int a, int b, const char op) {
	if (op == '+') 
		return a + b;
	if (op == '-') 
		return a - b;
	if (op == '*') 
		return a * b;
	if (op == '/') {
		if (b == 0) 
			throw std::invalid_argument("Division by zero");
		return a / b;
	}
	return 0;
}

RPN::RPN(const RPN& rhs){
	*this = rhs;
}

RPN::~RPN(){
	
}

RPN& RPN::operator=(const RPN& rhs){
	_number = rhs._number;
	_op = rhs._op;
	return *this;
}

const char *RPN::WrongInput::what() const throw(){
	return "Wrong input";
}
