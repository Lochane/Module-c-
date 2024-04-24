/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:50:16 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 18:03:38 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat Bob("Bob", 50);
	PresidentialPardonForm form("Patrick");
	try {
		Bob.signForm(form);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	Bob.executeForm(form);
}