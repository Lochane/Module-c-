/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:18:08 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/20 20:49:58 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN{
	private :
		std::stack<char> _operator;	
		std::stack<int> _number;
	public :
		RPN();
		RPN(const RPN& rhs);
		~RPN();
		RPN &operator=(const RPN& rhs);
		std::stack<char> CreateStack(std::string expre);
		
	
};


#endif