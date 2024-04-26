/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:50:16 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/26 18:42:42 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	Bureaucrat Steve("Steve", 1);
	AForm* rrf;
	
	try {
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		Steve.signForm(*rrf);
		std::cout << *rrf << std::endl;
		Steve.executeForm(*rrf);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	delete rrf;
}