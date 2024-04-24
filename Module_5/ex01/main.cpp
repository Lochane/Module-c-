/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:24:05 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 02:53:08 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	
	try {
		Bureaucrat Dwight("Dwight Schrute", 50);
		Form form("Dunder Mifflin annual sales", 35, 20);
		std::cout << std::endl << "Before :" << std::endl << form << std::endl;
		try 
		{
			Dwight.signForm(form);
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl << "After :" << std::endl << form << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl << "\t----------------\n" << std::endl;
	try {
		
		Bureaucrat Michael("Michael Scott", 1);
		Form form("Dunder Mifflin annual sales", 35, 20);
		std::cout << std::endl << "Before :" << std::endl << form << std::endl;
		try
		{
			Michael.signForm(form);
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl << "After :" << std::endl << form << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}