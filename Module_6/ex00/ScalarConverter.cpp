/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:47:54 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/06 18:25:01 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// void ScalarConverter::CheckType(std::string input) {
	
// 	char *endptr;
	
// 	if (input.length() == 1 && isdigit(input[0]))
// 		_type = CHAR;
// 	else if (strtol(input.c_str(), &endptr, 10) && !endptr[0])
// 		_type = INT;
// 	else if (strtod(input.c_str(), &endptr) && !endptr[0])
// 		_type = DOUBLE;
// 	else if (strtof(input.c_str(), &endptr) && !endptr[0])
// 		_type = FLOAT;	
// 	else
// 		throw WrongInput();
		
// }

static int	CountAfterPoint(std::string input) {
	int count = 0;
	for (int i = input.find_first_of("."); input[i]; i++){
		if (isdigit(input[i]))
			count++;
	}
	if (count == 0)
		count += 1;	
	return count;
}

static void ConvertFromDouble(double dnb, int n)
{
	char c = static_cast<char>(dnb);
	int nb = static_cast<int>(dnb);
	float fnb = static_cast<float>(dnb);
	std::cout << std::setprecision(n);
	std::cout << std::fixed;
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << fnb << "f" << std::endl;
	std::cout << "double: " << dnb << std::endl;
}

static void ConvertFromFloat(float fnb, int n)
{
	char c = static_cast<char>(fnb);
	int nb = static_cast<int>(fnb);
	double dnb = static_cast<double>(fnb);
	std::cout << std::setprecision(n);
	std::cout << std::fixed;
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << fnb << "f" << std::endl;
	std::cout << "double: " << dnb << std::endl;
}

static void ConvertFromInt(int nb, int n)
{
	char c = static_cast<char>(nb);
	float fnb = static_cast<float>(nb);
	double dnb = static_cast<double>(nb);
	std::cout << std::setprecision(n);
	std::cout << std::fixed;
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << fnb << "f" << std::endl;
	std::cout << "double: " << dnb << std::endl;
}

static void ConvertFromChar(char c, int n)
{
	int nb = static_cast<int>(c);
	float fnb = static_cast<float>(nb);
	double dnb = static_cast<double>(nb);
	std::cout << std::setprecision(n);
	std::cout << std::fixed;
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << fnb << "f" << std::endl;
	std::cout << "double: " << dnb << std::endl;
}

void ScalarConverter::convert(std::string input){
	int n = CountAfterPoint(input);
	
	char *endptr;
	Type _type;
	
	if (input.length() == 1 && !isdigit(input[0]))
		_type = CHAR;
	else if (strtol(input.c_str(), &endptr, 10) && endptr == NULL)
		_type = INT;
	else if (strtod(input.c_str(), &endptr) && endptr == NULL)
		_type = DOUBLE;
	else if (strtof(input.c_str(), &endptr) && endptr == NULL)
		_type = FLOAT;	
	else{
		std::cout << endptr;
		throw WrongInput();
	}
	switch (_type) {
		case CHAR:
			ConvertFromChar(input[0], n);
			return;
		case INT :
			ConvertFromInt(atoi(input.c_str()), n);
			return;
		case FLOAT:
			ConvertFromFloat(atof(input.c_str()), n);
			return;
		case DOUBLE:
			ConvertFromDouble(atof(input.c_str()), n);
			return;
		default:
			return;
	}
}

const char* ScalarConverter::WrongInput::what() const throw() {
	return "Error: Wrong input\n";
}