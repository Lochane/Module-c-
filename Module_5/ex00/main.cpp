/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:24:05 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 14:53:45 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	
	try 
	{
		
		Bureaucrat Dwight("Dwight Schrute", 149);
		std::cout << "Before :" << std::endl << Dwight << std::endl;
		try
		{
			Dwight.decrementGrade();
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}	
		std::cout << "After :" << std::endl << Dwight << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
		try 
	{
		
		Bureaucrat Michael("Michael Scott", 1);
		std::cout << "Before :" << std::endl << Michael << std::endl;

		try
		{
			Michael.incrementGrade();
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}	
		std::cout << "After :" << std::endl << Michael << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}