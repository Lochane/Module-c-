/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:12:05 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/06 16:04:10 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>

enum Type {
	CHAR, // 0
	INT,  // 1
	DOUBLE, // 2
	FLOAT, // 3
	
};

class ScalarConverter {
	private:
		ScalarConverter();

	public:
		static void convert(std::string input);
		// void CheckType(std::string input);
		// Type _type;
	class WrongInput : public std::exception{
		virtual const char* what() const throw();
	};

};

#endif