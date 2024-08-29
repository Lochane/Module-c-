/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:18:08 by lsouquie          #+#    #+#             */
/*   Updated: 2024/08/29 19:00:31 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

class RPN{
	private :
		RPN();
		std::stack<int> _number;
		std::stack<char> _op;
		int	ft_isdigit(int c);
		void CheckIntergrity(std::string expre);
		int DoTheThing(int a, int b, const char op);
		RPN();
		
	public :
		RPN(std::string expre);
		RPN(const RPN& rhs);
		~RPN();
		RPN &operator=(const RPN& rhs);

		
		class WrongInput : public std::exception{
			virtual const char* what() const throw();
		};
		
};


#endif