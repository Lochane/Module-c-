/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:18:08 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/21 17:03:11 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

class RPN{
	private :
		RPN();
		std::stack<int> _number;
	public :
		RPN(std::string expre);
		// RPN(const RPN& rhs);
		~RPN();
		// RPN &operator=(const RPN& rhs);
		int	ft_isdigit(int c);
		void CheckIntergrity(std::string expre);
		
		class WrongInput : public std::exception{
			virtual const char* what() const throw();
		};
};


#endif